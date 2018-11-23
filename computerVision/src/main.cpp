#include "ICamera.h"
#include "RaspiCamera.h"

#include <ctime>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <raspicam/raspicam.h>
#include <thread>

using namespace std;

int main ( int argc,char **argv ) 
{
	ICamera* cam = new RaspiCamera();

	cam->Capture();
	cam->Save("./raspicam_image.ppm");

	delete cam;

	return 0;
}