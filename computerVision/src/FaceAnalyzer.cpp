#include "FaceAnalyzer"

///////////////////////////
//Constructor/ Destructor
///////////////////////////
    FaceAnalyzer::FaceAnalyzer(const std::string& cascadeFile)
    {
        if (!cascade.load(cascadeFile)) throw std::runtime_error("Cannot open cascadefile:" + cascadeFile);
    }

    FaceAnalyzer::~FaceAnalyzer()
    {

    }