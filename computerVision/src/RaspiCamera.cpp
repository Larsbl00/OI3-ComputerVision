#include "RaspiCamera.h"

/////////////////////////
//Public Methods
/////////////////////////

RaspiCamera::RaspiCamera()
    :imageData(new unsigned char[camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)])
{
    this->OpenCamera();
    std::cout << "Booting camera, please wait for " 
        << (float) CAMERA_BOOT_TIME_MICROS/1000000 << " seconds" << std::endl;
    
    usleep(CAMERA_BOOT_TIME_MICROS);
}

RaspiCamera::~RaspiCamera()
{
    this->StopCamera();
    delete[] this->imageData;
}

void RaspiCamera::Capture()
{
    this->camera.grab();
    this->camera.retrieve(this->imageData, raspicam::RASPICAM_FORMAT_RGB);
}

const void* RaspiCamera::GetImageData() const
{
    return this->imageData;
}

void RaspiCamera::Save(const std::string& fileName)
{
    std::ofstream outFile (fileName, std::ios::binary);
    outFile << "P6\n" << camera.getWidth() << " " << camera.getHeight() << " 255\n";
	outFile.write((char*) imageData, camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB));
    std::cout << "Saved image as \"" << fileName << "\"" << std::endl;
}

///////////////////////////
//Private Methods
/////////////////////////

void RaspiCamera::OpenCamera()
{
    if (!camera.open()) 
    {
        std::domain_error("Error opening camera");  
    }
}

void RaspiCamera::StopCamera()
{
    if (camera.open())
    {
        camera.release();
    }
}