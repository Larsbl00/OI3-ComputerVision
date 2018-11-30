#ifndef FACE_ANALYZER
#define FACE_ANALYZER

#include "ICvAnalyzer.h"

#include <string>

class FaceAnalyzer : public ICvAnalyze
{
    public:
        FaceAnalyzer(const std::string& cascadeFile);

        std::vector<cv::Rect>& Analyze(const cv::Mat& material);

};

#endif