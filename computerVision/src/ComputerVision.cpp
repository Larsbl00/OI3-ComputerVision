#include "ComputerVision.h"

///////////////////////////
//Constructor/ Destructor
///////////////////////////
ComputerVision::ComputerVision(ICvCamera& camera, ICvAnalyze& faceAnalyzer)
    :camera(camera), faceAnalyzer(faceAnalyzer)
{

}

ComputerVision::~ComputerVision();
{
    
}

///////////////////////////
//Public Functions
///////////////////////////
std::vector<Face>& ComputerVision::GetFaces()
{
    return this->faces;
}

void ComputerVision::ScanFaces()
{
    this->camera.Capture();
    cv::Mat& frame = this->camera->GetImageData();

    //Check if the frame is empty, return if so
    if (frame.empty()) return;

    //Equalize.
    cv::equalizeHist(frame, frame);

    //Analyze frame for faces
    auto& faces = faceAnalyzer.Analyze(frame);
}