cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Sphere)

variable_watch(VTK_DIR)

if(DEFINED ENV{VTK_DIR})
    message("VTK_DIR: $ENV{VTK_DIR}")
else()
    message(FATAL_ERROR "VTK_DIR environment variable is not defined.")
endif()

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "Sphere: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(Sphere MACOSX_BUNDLE Sphere.cxx )
  target_link_libraries(Sphere PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS Sphere
  MODULES ${VTK_LIBRARIES}
)