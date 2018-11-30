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

#define CASCADE_FILE_FACE ("./haarcascades/haarcascade_frontalface_alt.xml")
#define CASCADE_FILE_EYES ("./haarcascades/haarcascade_eye_tree_eyeglasses.xml")

cv::CascadeClassifier FaceCascade;
cv::CascadeClassifier EyesCascade;

//////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////

bool LoadCascadeFromFile(cv::CascadeClassifier& classifier, const std::string& file)
{
    return classifier.load(file);
}

bool LoadHaarcascades()
{
    return (LoadCascadeFromFile(FaceCascade, CASCADE_FILE_FACE) //Load face file
    && LoadCascadeFromFile(EyesCascade, CASCADE_FILE_EYES));    //Load eye file
}

void GetEyesFromFrame(cv::Mat& frame, std::vector<cv::Rect>& eyes)
{
    //Detect eyes.
    EyesCascade.detectMultiScale(frame, eyes, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
}

void GetFacesFromFrame(cv::Mat& frame, std::vector<cv::Rect>& faces)
{
    //Detect faces.
    FaceCascade.detectMultiScale(frame, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
}

int main (int argc,char **argv ) 
{
	ICamera* cam = new RaspiCamera(240, 360);

    //Exit when you can't load te HAAR cascades
    if (!LoadHaarcascades())
    {
        exit(-1);
    }

    int iter = 0;
    int numOfImages = 100;
    std::vector<cv::Rect> faces;
	while(iter < numOfImages)
	{
		cam->Capture();

		cv::Mat& frame = cam->GetImageData();

		//Skip if empty
		if(!frame.empty())
		{
            //Equalize.
            cv::equalizeHist(frame, frame);

            //Get detected faces.
            GetFacesFromFrame(frame, faces);

            //Loop through faces.
            for(auto& face : faces)
            {
                //Get face center point.
                cv::Point faceCenter(face.x + face.width / 2.0, face.y + face.height / 2.0);

                //Draw ellipse on screen where the face is detected.
                cv::ellipse(frame, faceCenter, cv::Size( face.width / 2.0, face.height / 2.0),
                    0, 0, 360, cv::Scalar( 0, 0, 255 ), 4, 8, 0);
            }
            
            cam->Save("./images/image_with_highlighting (" + std::to_string(iter) + ").jpg");
            std::cout << "Image number: " << iter << std::endl;

		}
        iter++;
	}
    printf("done\n");

	delete cam;

	return 0;
}