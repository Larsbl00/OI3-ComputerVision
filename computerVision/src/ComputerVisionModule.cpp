#include "ComputerVisionModule.h"


ComputerVisionModule::ComputerVisionModule(ICvCamera &cam, IVision &cv)
    :camera(cam), cv(cv)
{

}

ComputerVisionModule::~ComputerVisionModule()
{

}

////////////////////////
//Public functions
////////////////////////

void ComputerVisionModule::Update()
{
    size_t iterator = 0;
    while (true)
    {
        cv.ScanFaces();

        for (auto& face : cv.GetFaces())
        {
            std::cout << "Detected face: " << iterator << " -> (" << (float)face.center.x/320 << ", " << (float)face.center.y/240 << ")"<< std::endl;
            cv::ellipse(camera.GetImageData(), cv::Point(face.center.x, face.center.y),
                        cv::Size(face.size.width / 2.0, face.size.height / 2.0), 0, 0, 360,
                        cv::Scalar(0, 0, 255), 4, 8, 0);
        }

        camera.Save("./images/image(" + std::to_string(iterator) + ").jpg");
        std::cout << "Image #" << iterator << std::endl;

        iterator++;
    }
}