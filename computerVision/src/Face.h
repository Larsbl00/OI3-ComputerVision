#ifndef FACE_H
#define FACE_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

struct Face 
{
    public:
        const cv::Point center;
        const cv::Rect face;

        Face(const cv::Rect& faceRect);
};


#endif