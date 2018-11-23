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

//////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////

bool LoadHaarcascades()
{
    //Load face cascade.
    if(!FaceCascade.load(FaceCascadeFileName))
    {  
        std::cout << "ERROR: cannot load face cascade." << std::endl;
        return false; 
    }

    //Load eye cascade.
    if(!EyesCascade.load(EyesCascadeFileName))
    { 
        std::cout << "ERROR: cannot load eyes cascade." << std::endl;
        return false; 
    }

    return true;
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

int main ( int argc,char **argv ) 
{
	ICamera* cam = new RaspiCamera();

    if (!LoadHaarcascades())
    {
        exit(-1);
    }

    int iter = 0;
    int numOfImages = 240;
    std::vector<cv::Rect> faces;
	while(iter < numOfImages)
	{
		cam->Capture();

		cv::Mat& frame = cam->GetImageData();

		//Break if frame is empty.
		if(!frame.empty())
		{
            //Convert and equalize frame.
            //cv::cvtColor(frame, frameGrayscale, cv::COLOR_BGR2GRAY );

            //Equalize.
            cv::equalizeHist(frame, frame);

            //Get detected faces.
            GetFacesFromFrame(frame, faces);

            //Loop through faces.
            for(auto face : faces)
            {
                //Get face center point.
                cv::Point faceCenter(face.x + face.width / 2.0, face.y + face.height / 2.0);

                //Draw ellipse on screen where the face is detected.
                cv::ellipse(frame, faceCenter, cv::Size( face.width / 2.0, face.height / 2.0), 0, 0, 360, cv::Scalar( 0, 0, 255 ), 4, 8, 0);
                /*
                //Get frame frame.
                cv::Mat faceFrame = frameGrayscale(faces[i]);

                //Get faces.
                std::vector<cv::Rect> eyes = GetEyesFromFrame(faceFrame);
                
                //Draw ellipse on screen where the eyes are detected.
                for( size_t j = 0; j < eyes.size(); j++ )
                {
                    //Get eye center point.
                    cv::Point eyeCenter(faces[i].x + eyes[j].x + eyes[j].width / 2.0, faces[i].y + eyes[j].y + eyes[j].height / 2.0 );
                    
                    //Get eye radius.
                    int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);

                    //Draw circle.
                    cv::circle( frame, eyeCenter, radius, cv::Scalar( 255, 0, 0 ), 2, 4, 0 );
                }
                */
            }
            
            cam->Save("./images/image_with_highlighting (" + std::to_string(iter) + ").jpg");
            printf("%i\n", iter);

		}
        iter++;
	}
    printf("done\n");

	delete cam;

	return 0;
}