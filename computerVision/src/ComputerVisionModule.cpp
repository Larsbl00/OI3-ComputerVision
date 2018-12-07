#include "ComputerVisionModule.h"


ComputerVisionModule::ComputerVisionModule(IVision &cv)
    :cv(cv), cvThread(NULL)
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
    if (cvThread == NULL)
    {
        cvThread = new thread(Update);
    } 
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
    cv.ScanFaces();

    for (auto &face : cv.GetFaces())
    {
        if (!face.face.empty())
        {
            std::cout << "Detected face -> (" << face.face.x << ", " << face.face.y << ")" << std::endl;
            cv::ellipse(raspiCam->GetImageData(), face.center,
                        cv::Size(face.face.width / 2.0, face.face.height / 2.0), 0, 0, 360,
                        cv::Scalar(0, 0, 255), 4, 8, 0);
        }
    }
}