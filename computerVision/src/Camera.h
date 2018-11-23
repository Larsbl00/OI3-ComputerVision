#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <stdexcept>

class Camera
{
    public:

        Camera();
        ~Camera();

        void Capture();
        void Capture(int16_t frameCount);

    private:

        raspicam::RaspiCam_Cv camera;
        cv::Mat image;

        void OpenCamera();
        void StopCamera();
};

#endif