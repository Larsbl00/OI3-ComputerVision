#ifndef COMPUTER_VISION_MODULE_H
#define COMPUTER_VISION_MODULE_H

#include "ICvAnalyzer.h"
#include "ICvCamera.h"
#include "IVision.h"

#include <iostream>
#include <thread>

class ComputerVisionModule
{
    public:
        ComputerVisionModule(ICvCamera &cam, IVision &cv);
        ~ComputerVisionModule();

        void Start();
        void Stop();

    private:
        ICvCamera &camera;
        IVision &cv;
        std::thread* cvThread;

        static void Update();
};

#endif