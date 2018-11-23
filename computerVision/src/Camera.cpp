#include "Camera.h"

/////////////////////////
//Public Methods
/////////////////////////

Camera::Camera()
{
    //set camera params
	this->Camera.set(CV_CAP_PROP_FORMAT, CV_8UC1);
    this->OpenCamera();
}

Camera::~Camera()
{
    this->StopCamera();
}

void Camera::Capture()
{
    this->Camera.grab();
    this->Camera.retrieve(image);
}

void Camera::Capture(int16_t frameCount)
{
    time(&this->timer_begin);
    for (int16_t i = 0; i < frameCount; i++)
    {
        this->Capture();
    }
}


///////////////////////////
//Private Methods
/////////////////////////

void Camera::OpenCamera()
{
    if (!camera.open()) 
    {
        std::domain_error("Error opening camera");  
    }
}

void Camera::StopCamera()
{
    if (camera.open())
    {
        camera.release();
    }
}