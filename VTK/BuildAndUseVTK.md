# Build VTK
mkdir VTK
cd VTK
mkdir src
mkdir bin
- copy or clone source VTK code into src
- install cmake
- run cmake guid and set src and bin directories > press configure then press generate
- go to bin/VTK.sln and right click ALL_BUILD>Build (will take ~10 minutes)
- Set Environment Variables
	- add location of build "Path" (e.g., E:\VTK\bin\bin\Debug <- folder of .dll's)
	- add new system variable VTK_DIR (e.g., E:\VTK\bin\lib\cmake\vtk-9.3)

# Create code for project using VTK
mkdir sphere
cd sphere
mkdir src
	- add sphere.cpp and CMakeLists.txt
mkdir bin

## Option 1
- run cmake guid and set src and bin directories > press configure then press generate
- for error of VTK_DIR manually set VTK_DIR to location of vtk build files (e.g.,., VTK\bin\lib\cmake\vtk-9.3) then generate
	- or add to CMakeLists.txt : SET(VTK_DIR "E:/VTK/bin/lib/cmake/vtk-9.3" CACHE PATH "VTK directory override" FORCE)
- in bin, open the .sln file and build
- run .exe created (e.g., in "Debug" folder)

## Option 2
- Go into the src folder, right click, open with visual studio
- build

