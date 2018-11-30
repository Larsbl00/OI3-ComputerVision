#ifndef ICV_CAMERA_H
#define ICV_AMERA_H

#include <cstdint>
#include <opencv2/core.hpp>
#include <string>

class ICvCamera
{
    public:
        virtual ~ICvCamera(){}
        virtual cv::Mat& GetImageData() = 0;
        virtual void Capture() = 0;
        virtual void Save(const std::string& fileName) = 0;
};

#endif