#ifndef COMPUTER_VISION_MODULE_H
#define COMPUTER_VISION_MODULE_H

#include "ICvAnalyzer.h"
#include "ICvCamera.h"
#include "IVision.h"

#include <iostream>

class ComputerVisionModule
{
    public:
        ComputerVisionModule(ICvCamera& cam, IVision& cv);
        ~ComputerVisionModule();

        void Update();

    private:
        ICvCamera& camera;
        IVision& cv;
        
};

#endif