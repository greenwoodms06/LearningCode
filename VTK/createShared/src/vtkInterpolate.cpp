#include "vtkInterpolate.h"

#include <vtkSmartPointer.h>
#include <vtkDataReader.h>
#include <vtkDataSetReader.h>
#include <vtkDataSet.h>

namespace vtk {

    bool ReadData(const std::string& filename)
    {
        // Initialize class and read data
        vtkNew<vtkDataSetReader> reader;
        reader->SetFileName(filename.c_str());
        reader->Update();

        //vtkSmartPointer<vtkDataSet> dataSet = vtkSmartPointer<vtkDataSet>::New();
        vtkSmartPointer<vtkDataSet> dataSet = reader->GetOutput();
        double* bounds = dataSet->GetBounds();
        bool isRectiLinear = dataSet->IsA("vtkRectilinearGrid");

        return 0;
    }
} // namespace vtkutilities