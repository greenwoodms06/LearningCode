cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(MyProject)

variable_watch(VTK_DIR)

if(DEFINED ENV{VTK_DIR})
    message("VTK_DIR: $ENV{VTK_DIR}")
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
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "MyProject: Unable to find the VTK build folder.")
endif()

# Add the include directory
include_directories(include)

# Define location of source files
set(SOURCE_FILES main.cpp vtkInterpolate.cpp)

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