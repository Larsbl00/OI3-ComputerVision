#include "FaceAnalyzer"

///////////////////////////
//Constructor/ Destructor
///////////////////////////
FaceAnalyzer::FaceAnalyzer(const std::string& cascadeFile)
{
    if (!this->cascade.load(cascadeFile)) throw std::runtime_error("Cannot open cascadefile:" + cascadeFile);
}

FaceAnalyzer::~FaceAnalyzer()
{

}

///////////////////////////
//Public Functions
///////////////////////////

std::vector<cv::Rect>& FaceAnalyzer::Analyze(const cv::Mat& matrix)
{
    this->cascade.detectMultiScale(matrix, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    return faces;
}