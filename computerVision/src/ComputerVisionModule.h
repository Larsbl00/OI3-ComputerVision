#ifndef COMPUTER_VISION_MODULE_H
#define COMPUTER_VISION_MODULE_H

#include "IVision.h"
#include "ICvAnalyzer.h"

class ComputerVisionModule
{
    public:
        ComputerVisionModule(IVision &cv);

        void Start();
        void Stop();
};

#endif