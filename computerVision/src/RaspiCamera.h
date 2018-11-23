#ifndef RASPI_CAMERA_H
#define RASPI_CAMERA_H

#include "ICamera.h"

#include <iostream>
#include <stdexcept>

class RaspiCamera : public ICamera
{
    public:

        RaspiCamera();
        ~RaspiCamera();

        void Capture();
        void Capture(int16_t frameCount);

    private:

        raspicam::RaspiCam_Cv camera;
        cv::Mat image;

        void OpenCamera();
        void StopCamera();
};

#endif