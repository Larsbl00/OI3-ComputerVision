#ifndef COMPUTER_VISION_H
#define COMPUTER_VISION_H

#include "Face.h"
#include "IVision.h"
#include "ICvAnalyze.h"
#include "ICvCamera.h"

#include <vector>

class ComputerVision : public IVision
{
    public: 
        ComputerVision(ICvCamera& camera, ICvAnalyze& faceAnalyzer);    
        ~ComputerVision();

        std::vector<Face>& GetFaces();
        void ScanFaces();

    private:
        ICvCamera& camera;
        ICvAnalyze& faceAnalyzer;
};

#endif