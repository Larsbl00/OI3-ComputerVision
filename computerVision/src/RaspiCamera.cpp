#include "RaspiCamera.h"

/////////////////////////
//Public Methods
/////////////////////////

RaspiCamera::RaspiCamera()
{
    //set camera params
	this->Camera.set(CV_CAP_PROP_FORMAT, CV_8UC1);
    this->OpenCamera();
}

RaspiCamera::~RaspiCamera()
{
    this->StopCamera();
}

void RaspiCamera::RaspiCamera()
{
    this->Camera.grab();
    this->Camera.retrieve(image);
}

void RaspiCamera::RaspiCamera(int16_t frameCount)
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

void RaspiCamera::OpenCamera()
{
    if (!camera.open()) 
    {
        std::domain_error("Error opening camera");  
    }
}

void RaspiCamera::StopCamera()
{
    if (camera.open())
    {
        camera.release();
    }
}