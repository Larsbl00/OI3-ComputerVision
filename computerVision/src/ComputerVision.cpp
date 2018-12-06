#include "ComputerVision.h"

///////////////////////////
//Constructor/ Destructor
///////////////////////////
ComputerVision::ComputerVision(ICvCamera &camera, ICvAnalyze &faceAnalyzer)
    : camera(camera), faceAnalyzer(faceAnalyzer)
{
}

ComputerVision::~ComputerVision()
{
}

///////////////////////////
//Public Functions
///////////////////////////
std::vector<Face> &ComputerVision::GetFaces()
{
    return this->faces;
}

void ComputerVision::ScanFaces()
{
    //Clear the list containing all faces
    this->faces.clear();

    //Take a picture of the current screen
    this->camera.Capture();

    cv::Mat &frame = this->camera.GetImageData();

    //Check if the frame is empty, return if so
    if (frame.empty()) return;

    //Equalize.
    cv::equalizeHist(frame, frame);

    //Analyze rectangles of faces
    std::vector<cv::Rect> &faceRectangles = faceAnalyzer.Analyze(frame);

    for (auto& rect : faceRectangles)
    {
        Face person(rect);

        this->faces.push_back(person);
    }
}