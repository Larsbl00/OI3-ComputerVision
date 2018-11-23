#ifndef ICAMERA_H
#define ICAMERA_H

#include <cstdint>
#include <string>

class ICamera
{
    public:
        virtual ~ICamera(){}
        const void* GetImageData() const;
        virtual void Capture() = 0;
        virtual void Save(const std::string& fileName) = 0;
};

#endif