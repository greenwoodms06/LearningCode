cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(MyProject)

# Optional location if VTK not on PATH
set(VTK_DIR_header E:/VTK/bin/lib/cmake/vtk-9.3)
set(VTK_DIR_dll E:/VTK/bin/bin/Debug)

variable_watch(VTK_DIR)

if(NOT DEFINED ENV{VTK_DIR})
    set(VTK_DIR ${VTK_DIR_header})
endif()

if(DEFINED ENV{VTK_DIR})
    message("VTK_DIR: $ENV{VTK_DIR}")
elseif(VTK_DIR)
    message("VTK_DIR: ${VTK_DIR}")
else()
    message(FATAL_ERROR "VTK_DIR environment variable is not defined.")
endif()

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersPoints
  IOLegacy
  ImagingCore
  FiltersSources
  PATHS ${VTK_DIR_dll}
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "MyProject: Unable to find the VTK build folder.")
endif()

# Add the include directory
include_directories(include)

# Define location of source files
set(SOURCE_FILES src/main.cpp src/vtkInterpolate.cpp)

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(RunMe MACOSX_BUNDLE ${SOURCE_FILES} )
  target_link_libraries(RunMe PRIVATE ${VTK_LIBRARIES}
)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS RunMe
  MODULES ${VTK_LIBRARIES}
)
add_custom_command(
    TARGET RunMe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:RunMe>
        $<TARGET_FILE_DIR:RunMe>
        COMMAND_EXPAND_LISTS
)

install(TARGETS RunMe DESTINATION bin)
install(FILES $<TARGET_RUNTIME_DLLS:RunMe> DESTINATION bin)