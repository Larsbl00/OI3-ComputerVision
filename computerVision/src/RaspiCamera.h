#ifndef RASPI_CAMERA_H
#define RASPI_CAMERA_H

#include "ICamera.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <raspicam/raspicam.h>
#include <unistd.h>

#define CAMERA_BOOT_TIME (3000000)

class RaspiCamera : public ICamera
{
    public:

        RaspiCamera();
        ~RaspiCamera();

        void Capture();
        void Capture(int16_t frameCount);

        void Save(const std::string& fileName);

    private:

        raspicam::RaspiCam camera;
        unsigned char* imageData;

        void OpenCamera();
        void StopCamera();
};

#endif