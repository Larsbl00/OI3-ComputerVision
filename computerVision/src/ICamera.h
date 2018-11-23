#ifndef ICAMERA_H
#define ICAMERA_H

#include <cstdint>
#include <opencv2/core.hpp>
#include <string>

class ICamera
{
    public:
        virtual ~ICamera(){}
        virtual cv::Mat& GetImageData() = 0;
        virtual void Capture() = 0;
        virtual void Save(const std::string& fileName) = 0;
};

#endif