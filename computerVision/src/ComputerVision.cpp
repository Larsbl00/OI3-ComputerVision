#include "ComputerVision.h"

///////////////////////////
//Constructor/ Destructor
///////////////////////////
ComputerVision::ComputerVision(ICvCamera& camera, ICvAnalyze& faceAnalyzer)
    :camera(camera), faceAnalyzer(faceAnalyzer), faces(NULL)
{

}

ComputerVision::~ComputerVision()
{
    //Pointer set to NULL and not deleted,
    //since it points to an externally stored vector
    this->faces = NULL; 
}

///////////////////////////
//Public Functions
///////////////////////////
std::vector<Face>& ComputerVision::GetFaces()
{
    return *this->faces;
}

void ComputerVision::ScanFaces()
{
    this->camera.Capture();
    cv::Mat& frame = this->camera.GetImageData();

    //Check if the frame is empty, return if so
    if (frame.empty()) return;

    //Equalize.
    cv::equalizeHist(frame, frame);

    //Analyze frame for faces
    faces = &faceAnalyzer.Analyze(frame);
}