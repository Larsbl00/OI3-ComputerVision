#ifndef ICAMERA_H
#define ICAMERA_H

#include <cstdint>
#include <raspicam/raspicam_cv.h>

class ICamera
{
    public:
        ~ICamera(){}

        virtual void Capture() = 0;
        virtual void Capture(int16_t frameCount) = 0;
};

#endif