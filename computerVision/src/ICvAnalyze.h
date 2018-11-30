#ifndef ICV_ANALYZE_H
#define ICV_ANALYZE_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

class ICvAnalyze
{
    public:
        virtual ~ICvAnalyze(){}

        virtual std::vector<cv::Rect>& Analyze(const cv::Mat& material) = 0;
};

#endif