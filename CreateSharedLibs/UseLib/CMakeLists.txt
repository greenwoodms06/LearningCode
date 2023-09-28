
cmake_minimum_required(VERSION 3.10)

project(SquareRootApp)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create the executable and link against the DLL
add_executable(SquareRootApp src/main.cpp)

# Link the executable with the DLL
IF (WIN32)
  target_link_libraries(SquareRootApp PRIVATE ${CMAKE_SOURCE_DIR}/../CreateLib/build/lib/MathFunctions.dll)
ELSE()
  target_link_libraries(SquareRootApp PRIVATE ${CMAKE_SOURCE_DIR}/../CreateLib/build/lib/MathFunctions.so)
ENDIF()

# Include the directory containing the header files
target_include_directories(SquareRootApp PRIVATE ${CMAKE_SOURCE_DIR}/../CreateLib/include)