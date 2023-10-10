#include "vtkInterpolate.h"

#include <vtkSmartPointer.h>
#include <vtkDataReader.h>
#include <vtkDataSetReader.h>
#include <vtkDataSet.h>
//#include <vtkPolyData.h>
#include <vtkPointInterpolator.h>
#include <vtkFloatArray.h>
#include <vtkLinearKernel.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkPoints.h>
#include <vtkLineSource.h>
#include <vtkPointSource.h>
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
        vtkSmartPointer<vtkPointData> pointData = dataSet->GetPointData();
        vtkSmartPointer<vtkCellData> cellData = dataSet->GetCellData();
        const char* name = cellData->GetArrayName(0);

        vtkNew<vtkPoints> points;
        points->InsertNextPoint(1.0, 2.0, 3.0);
        vtkNew<vtkPolyData> polyData;
        polyData->SetPoints(points);
        //vtkNew<vtkDataSet> dataSet = polyData;
        vtkSmartPointer<vtkDataSet> pointsDataSet = polyData;

        //vtkNew<vtkPointSource> points;
        //points->SetNumberOfPoints(1);
        //double myarray[3] = {1.0,2.0,3.0};
        //points->SetCenter(myarray);

        vtkNew<vtkPointInterpolator> interpolator;
        interpolator->SetInputData(pointsDataSet);
        interpolator->SetSourceData(dataSet);


        vtkSmartPointer<vtkDataSet> dataInterp = interpolator->GetOutput();
        //interpolator->SetInputData(surface);
        //interpolator->SetSourceData(points);
        //pointData->GetAbstractArray(0)-Get
        ////
        //vtkSmartPointer<vtkPointInterpolator> interpolator = vtkSmartPointer<vtkPointInterpolator>::New();
        //interpolator->SetSourceData(dataSet);
        //interpolator->SetInputData(dataSet);
        //pointInterpolator->
        //pointInterpolator->SetInputDataObject()
        //double x = 1.0;
        //double y = 2.0;
        //double z = 3.0;

        // Set the interpolation kernel (linear or nearest neighbor)
        //interpolator->SetKernel(vtkPointInterpolator::LINEAR); //doens't work, unclear what the input argument should be

        // Set the position to interpolate
        //double interpolationPoint[3] = { 0.5, 0.5, 0.5 };
        //interpolator->SetInterpolationCoordinates(interpolationPoint);
        //interpolator->
        //vtkSmartPointer<vtkFloatArray> interpolatedValues = vtkSmartPointer<vtkFloatArray>::New();
        //interpolatedValues->SetNumberOfComponents(1);
        //interpolatedValues->SetName("InterpolatedValues");

        //pointInterpolator->SetSourcePosition(x, y, z);
        //pointInterpolator->Interpolate();
        return 0;
    }

    double InterpolateData(const std::string& filename, double x, double y, double z)
    {
        // Load the legacy VTK file
        vtkSmartPointer<vtkDataReader> reader = vtkSmartPointer<vtkDataReader>::New();
        reader->SetFileName(filename.c_str());
        reader->Update();
        int version = reader->GetFileVersion();
        //vtkSmartPointer<vtkPolyData> polyData = reader->GetOutput();
        std::cout << "version: " << version << std::endl;
        return 0;
        //// Get the point data
        //vtkSmartPointer<vtkPointData> pointData = reader->GetOutput()->GetPointData();
        //vtkSmartPointer<vtkDataArray> dataArray = pointData->GetScalars();

        //// Get the points and their coordinates
        //vtkSmartPointer<vtkPoints> points = reader->GetOutput()->GetPoints();

        //// Create a point interpolator
        //vtkSmartPointer<vtkPointInterpolator> interpolator = vtkSmartPointer<vtkPointInterpolator>::New();
        //interpolator->SetInputData(points);
        //interpolator->SetSourceData(dataArray);

        //// Perform interpolation
        //double value[1];
        //interpolator->Interpolate(x, y, z, value);

        //return value[0];
    }

} // namespace vtkutilities