#include "ComputerVision.h"
#include "ComputerVisionModule.h"
#include "FaceAnalyzer.h"
#include "IVision.h"
#include "ICvAnalyzer.h"
#include "RaspiCamera.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <thread>
#include <unistd.h>

#define CASCADE_FILE_FACE ("./haarcascades/haarcascade_frontalface_alt.xml")
#define CASCADE_FILE_EYES ("./haarcascades/haarcascade_eye_tree_eyeglasses.xml")
#define IMAGE_COUNT (2000)
#define FACE_ANALYZER_SCALE_FACTOR (1.85f)
#define FACE_ANALYZER_NEIGHBOR_COUNT (2)

int main(int argc, char **argv)
{
    //Create camera
    ICvCamera *raspiCam = new RaspiCamera(320, 240);

    //Create face analyzer
    ICvAnalyze *faceAnalyzer = new FaceAnalyzer(CASCADE_FILE_FACE, FACE_ANALYZER_NEIGHBOR_COUNT, 
        FACE_ANALYZER_SCALE_FACTOR);

    //Create the vision
    IVision *computerVision = new ComputerVision(*raspiCam, *faceAnalyzer);

    ComputerVisionModule module(*raspiCam, *computerVision);

    //Sleep 10 seconds
    usleep(10000000);

    std::cout << "\n\n\nCompleted: " << IMAGE_COUNT << " images\n\n\n"
              << std::endl;

    //Clean up
    delete raspiCam;
    delete faceAnalyzer;
    delete computerVision;

    return 0;
}