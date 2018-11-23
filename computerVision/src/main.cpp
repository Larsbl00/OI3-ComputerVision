#include "ICamera.h"
#include "RaspiCamera.h"

#include <ctime>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <thread>

using namespace std;

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