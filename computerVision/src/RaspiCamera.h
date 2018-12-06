#ifndef RASPI_CAMERA_H
#define RASPI_CAMERA_H

#include "ICvCamera.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <raspicam/raspicam_cv.h>
#include <stdexcept>
#include <unistd.h>

class RaspiCamera : public ICvCamera
{
    public:

        RaspiCamera(size_t imageWidth, size_t imageHeight);
        ~RaspiCamera();

        void Capture();
        cv::Mat& GetImageData();
        void Save(const std::string& fileName);

    private:

        raspicam::RaspiCam_Cv camera;
        cv::Mat imageData;

        void OpenCamera();
        void StopCamera();
};

#endif
