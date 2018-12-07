#include "FaceAnalyzer.h"

///////////////////////////
//Constructor/ Destructor
///////////////////////////
FaceAnalyzer::FaceAnalyzer(const std::string& cascadeFile, uint8_t neighborCount, double scaleFactor)
    :neighbors(neighborCount), scaleFactor(scaleFactor)
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
    this->cascade.detectMultiScale(matrix, this->faces, this->scaleFactor, this->neighbors, cv::CASCADE_SCALE_IMAGE, 
        cv::Size(FACE_ANALYZER_MIN_WIDTH, FACE_ANALYZER_MIN_HEIGHT));
    return this->faces;
}