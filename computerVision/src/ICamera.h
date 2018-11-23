#ifndef ICAMERA_H
#define ICAMERA_H

#include <cstdint>
#include <string>

class ICamera
{
    public:
        virtual ~ICamera(){}

        virtual void Capture() = 0;
        virtual void Capture(int16_t frameCount) = 0;
        virtual void Save(const std::string& fileName) = 0;
};

#endif