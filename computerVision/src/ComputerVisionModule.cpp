#include "ComputerVisionModule.h"


ComputerVisionModule::ComputerVisionModule(IVision &cv)
    :cvThread(NULL)
{
    Start();
}

ComputerVisionModule::~ComputerVisionModule()
{
    Stop();
}

////////////////////////
//Public functions
////////////////////////

void ComputerVisionModule::Start()
{
    if (cvThread == NULL) cvThread = new thread(Update);
}

void ComputerVisionModule::Stop()
{
    if (cvThread != NULL)
    {
        cvThread->detach();
        delete cvThread;
        cvThread = NULL;
    }
}

////////////////////////
//Private functions
////////////////////////

void ComputerVisionModule::Update()
{
    
}