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

# Define location of source files
set(SOURCE_FILES src/main.cpp src/vtkInterpolate.cpp)

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

# Add the include directory
include_directories(include)

# Create the shared library
add_library(RunMe SHARED ${SOURCE_FILES})
    target_link_libraries(RunMe PRIVATE ${VTK_LIBRARIES}
)

# Add the include directory
# target_include_directories(RunMe PUBLIC ../include)

# Set the name and properties of the shared library
set_target_properties(RunMe PROPERTIES OUTPUT_NAME "RunMe" PREFIX "" WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

#add_executable(RunMe MACOSX_BUNDLE ${SOURCE_FILES} )
#  target_link_libraries(RunMe PRIVATE ${VTK_LIBRARIES}
#)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS RunMe
  MODULES ${VTK_LIBRARIES}
)