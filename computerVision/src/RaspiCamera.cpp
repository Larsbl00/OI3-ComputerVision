#include "RaspiCamera.h"

/////////////////////////
//Public Methods
/////////////////////////

RaspiCamera::RaspiCamera()
{
    this->camera.set(cv::CAP_PROP_FORMAT, CV_8UC1);
    this->OpenCamera();
    std::cout << "Booting camera, please wait for " 
        << (float) CAMERA_BOOT_TIME_MICROS/1000000 << " seconds" << std::endl;
    
    usleep(CAMERA_BOOT_TIME_MICROS);
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

const void* RaspiCamera::GetImageData() const
{
    return &this->imageData;
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