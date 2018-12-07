#ifndef FACE_ANALYZER
#define FACE_ANALYZER

#include "ICvAnalyzer.h"

#include <string>
#include <stdexcept>

#define FACE_ANALYZER_MIN_HEIGHT (30)
#define FACE_ANALYZER_MIN_WIDTH (30)

class FaceAnalyzer : public ICvAnalyze
{
    public:
        FaceAnalyzer(const std::string& cascadeFile, uint8_t neighborCount, double scaleFactor);
        ~FaceAnalyzer();

        std::vector<cv::Rect>& Analyze(const cv::Mat& matrix);
    
    private:
        cv::CascadeClassifier cascade;
        std::vector<cv::Rect> faces;
        uint8_t neighbors;
        double scaleFactor;
};

#endif