#include "RaspiCamera.h"

/////////////////////////
//Public Methods
/////////////////////////

RaspiCamera::RaspiCamera(size_t imageWidth, size_t imageHeight)
{
    this->camera.set(cv::CAP_PROP_FORMAT, CV_8UC1);
    this->camera.set(cv::CAP_PROP_FRAME_WIDTH, imageWidth);
    this->camera.set(cv::CAP_PROP_FRAME_HEIGHT, imageHeight);
    this->OpenCamera();
}

RaspiCamera::~RaspiCamera()
{
    this->StopCamera();
}

void RaspiCamera::Capture()
{
    this->camera.grab();
    this->camera.retrieve(this->imageData);
}

cv::Mat& RaspiCamera::GetImageData()
{
    return this->imageData;
}

void RaspiCamera::Save(const std::string& fileName)
{
    cv::imwrite(fileName, imageData);
}

///////////////////////////
//Private Methods
/////////////////////////

void RaspiCamera::OpenCamera()
{
    if (!camera.open()) 
    {
        std::domain_error("Error opening camera");  
    }
}

void RaspiCamera::StopCamera()
{
    camera.release();
}