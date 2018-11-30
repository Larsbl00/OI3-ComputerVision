#ifndef FACE_ANALYZER
#define FACE_ANALYZER

#include "ICvAnalyzer.h"

#include <string>
#include <stdexcept>

class FaceAnalyzer : public ICvAnalyze
{
    public:
        FaceAnalyzer(const std::string& cascadeFile);
        ~FaceAnalyzer();

        std::vector<cv::Rect>& Analyze(const cv::Mat& material);
    
    private:
        cv::CascadeClassifier cascade;
        std::vector<cv::Rect> faces;
};

#endif