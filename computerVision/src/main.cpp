#include "ComputerVision.h"
#include "IVision.h"

#include <ctime>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <unistd.h>
#include <iostream>
#include <thread>

#define CASCADE_FILE_FACE ("./haarcascades/haarcascade_frontalface_alt.xml")
#define CASCADE_FILE_EYES ("./haarcascades/haarcascade_eye_tree_eyeglasses.xml")


int main (int argc,char **argv ) 
{
    //Create camera
	ICvCamera* raspiCam = new RaspiCamera(240, 360);
    //Create face analyzer
    ICvAnalyze* faceAnalyzer = new FaceAnalyzer(CASCADE_FILE_FACE);

    //Create the vision
    IVision* computerVision = new ComputerVision(*raspiCam, *faceAnalyzer);

    int imageCount = 100;
    for (int i = 0; i < imageCount; i++)
    {
        computerVision->ScanFaces();

        for (auto& face : computerVision->GetFaces())
        {
            cv::Point faceCenter(face.x + face.width / 2.0, face.y + face.height / 2.0);
            cv::ellipse(frame, faceCenter, cv::Size( face.width / 2.0, face.height / 2.0),
                    0, 0, 360, cv::Scalar( 0, 0, 255 ), 4, 8, 0);

        }
        raspiCam->Save("./images/image_with_highlighting (" + std::to_string(i) + ").jpg");
        std::cout << "Saved image #" << i << std::endl;
    }
    
    printf("done\n");


    //Clean up
    delete raspiCam;
    delete faceAnalyzer;
    delete computerVision;

	return 0;
}