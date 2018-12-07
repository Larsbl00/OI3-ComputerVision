#ifndef COMPUTER_VISION_MODULE_H
#define COMPUTER_VISION_MODULE_H

#include "IVision.h"
#include "ICvAnalyzer.h"

#include <thread>

class ComputerVisionModule
{
    public:
        ComputerVisionModule(IVision &cv);
        ~ComputerVisionModule();

        void Start();
        void Stop();

    private:
        std::thread* cvThread;

        void Update();
};

#endif