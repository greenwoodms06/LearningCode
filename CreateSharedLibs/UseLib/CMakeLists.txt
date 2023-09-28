
cmake_minimum_required(VERSION 3.10)

project(SquareRootApp)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create the executable and link against the DLL
add_executable(SquareRootApp src/main.cpp)

# Link the executable with the LIB and copy the DLL to the executable path
IF (WIN32)
  target_link_libraries(SquareRootApp ${CMAKE_SOURCE_DIR}/../CreateLib/build/lib/MathFunctions.lib)
  set(MATHFUNCTIONS_DLL ${CMAKE_SOURCE_DIR}/../CreateLib/build/lib/MathFunctions.dll)
  add_custom_command(TARGET SquareRootApp POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   ${MATHFUNCTIONS_DLL} $<TARGET_FILE_DIR:SquareRootApp>)
ELSE()
  target_link_libraries(SquareRootApp PRIVATE ${CMAKE_SOURCE_DIR}/../CreateLib/build/lib/MathFunctions.so)
ENDIF()

# Include the directory containing the header files
target_include_directories(SquareRootApp PRIVATE ${CMAKE_SOURCE_DIR}/../CreateLib/include)