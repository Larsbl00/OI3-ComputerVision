#include "FaceAnalyzer.h"

///////////////////////////
//Constructor/ Destructor
///////////////////////////
FaceAnalyzer::FaceAnalyzer(const std::string& cascadeFile)
{
    if (!this->cascade.load(cascadeFile)) throw std::runtime_error("Cannot open cascadefile: " + cascadeFile);
}

FaceAnalyzer::~FaceAnalyzer()
{

}

///////////////////////////
//Public Functions
///////////////////////////

std::vector<cv::Rect>& FaceAnalyzer::Analyze(const cv::Mat& matrix)
{
    this->faces.clear();
    this->cascade.detectMultiScale(matrix, this->faces, 1.05, 4, 0 | cv::CASCADE_SCALE_IMAGE, 
        cv::Size(FACE_ANALYZER_MIN_WIDTH, FACE_ANALYZER_MIN_HEIGHT));
    return this->faces;
}