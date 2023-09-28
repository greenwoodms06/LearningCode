
cmake_minimum_required(VERSION 3.10)

project(MathFunctionsProject)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Set the output directory for the DLL
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add the include directory
include_directories(include)

# Define location of source files
set(SOURCE_FILES src/MathFunctions.cpp)

# Create the shared library
add_library(MathFunctions SHARED ${SOURCE_FILES})

# Set the name and properties of the shared library
set_target_properties(MathFunctions PROPERTIES OUTPUT_NAME "MathFunctions" PREFIX "")

# Copy the DLL to the output directory
add_custom_command(TARGET MathFunctions POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MathFunctions> ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)