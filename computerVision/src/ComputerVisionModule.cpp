#include "ComputerVisionModule.h"


ComputerVisionModule::ComputerVisionModule(ICvCamera &cam, IVision &cv)
    :camera(cam), cv(cv), cvThread(NULL)
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
        cvThread = new std::thread(this->Update);
        std::cout << "Vision Online..." << std::endl;
    } 
}

void ComputerVisionModule::Stop()
{
    if (cvThread != NULL)
    {
        cvThread->detach();
        delete cvThread;
        cvThread = NULL;
        std::cout << "Vision Offline..." << std::endl;
    }
}

////////////////////////
//Private functions
////////////////////////

//@TODO: Make sure the update function runs on a seperate thread
static void ComputerVisionModule::Update()
{
    size_t iterator = 0;
    while (true)
    {
        cv.ScanFaces();

        std::cout << "Image #" << iterator << std::endl;

        for (auto &face : cv.GetFaces())
        {
            if (!face.face.empty())
            {
                std::cout << "Detected face -> (" << face.face.x << ", " << face.face.y << ")" << std::endl;
                cv::ellipse(camera.GetImageData(), face.center,
                            cv::Size(face.face.width / 2.0, face.face.height / 2.0), 0, 0, 360,
                            cv::Scalar(0, 0, 255), 4, 8, 0);
            }
        }
        
        camera.Save("./images/image(" + std::to_string(iterator) + ").jpg");

        iterator++;
    }
}