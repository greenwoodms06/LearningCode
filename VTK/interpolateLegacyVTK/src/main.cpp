#include "vtkInterpolate.h"

#include <iostream>
#include <cmath>
#include <vtkSmartPointer.h>
#include <vtkDataReader.h>

int main()
{
    std::string filename = "E:/UnrealEngine/viper/unreal/viper_ar_hololens/Content/ViperDemo/NonAssetInclude/validation/mR_hr.vtk";
    double x = 1.0;  // Specify the x-coordinate
    double y = 2.0;  // Specify the y-coordinate
    double z = 3.0;  // Specify the z-coordinate
    
    bool reader = vtk::ReadData(filename);

    /*
    double interpolatedValue = vtk::InterpolateData(filename, x, y, z);

    if (std::isnan(interpolatedValue)) {
        // Point is outside the dataset
        // Handle accordingly
    }
    else {
        // Point is inside the dataset
        // Handle the interpolated value
        std::cout << "Interpolated value: " << interpolatedValue << std::endl;
    }
    */
    return 0;
}