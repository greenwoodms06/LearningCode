#ifndef VTK_VTKINTERPOLATE_H
#define VTK_VTKINTERPOLATE_H

#include <string>

namespace vtk {

    bool ReadData(const std::string& filename);
    //double InterpolateData(const std::string& filename, double x, double y, double z);

} // namespace vtkUtilities

#endif // VTKUTILITIES_VTKINTERPOLATOR_H