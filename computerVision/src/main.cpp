#include "ICamera.h"
#include "RaspiCamera.h"

#include <ctime>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <unistd.h>
#include <iostream>
#include <thread>

std::string FaceCascadeFileName = "./haarcascades/haarcascade_frontalface_alt.xml";
std::string EyesCascadeFileName = "./haarcascades/haarcascade_eye_tree_eyeglasses.xml";
cv::CascadeClassifier FaceCascade;
cv::CascadeClassifier EyesCascade;

int main ( int argc,char **argv ) 
{
	ICamera* cam = new RaspiCamera();

	cam->Capture();

	usleep(300000);

	cam->Capture();
	cam->Save("./raspicam_image.jpg");

	delete cam;

	return 0;
}