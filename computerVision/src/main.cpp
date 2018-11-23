#include <iostream>

using namespace std; 

int main(int argc, char** argv)
{
	//Start capture
	cout<<"Capturing "<<nCount<<" frames ...."<<endl;
	time ( &timer_begin );
	for ( int i=0; i<nCount; i++ ) {
		Camera.grab();
		Camera.retrieve ( image);
		if ( i%5==0 )  cout<<"\r captured "<<i<<" images"<<std::flush;
	}
	cout<<"Stop camera..."<<endl;
	Camera.release();
	//show time statistics
	time ( &timer_end ); /* get current time; same as: timer = time(NULL)  */
	double secondsElapsed = difftime ( timer_end,timer_begin );
	cout<< secondsElapsed<<" seconds for "<< nCount<<"  frames : FPS = "<<  ( float ) ( ( float ) ( nCount ) /secondsElapsed ) <<endl;
	//save image 
	cv::imwrite("raspicam_cv_image.jpg",image);
	cout<<"Image saved at raspicam_cv_image.jpg"<<endl;
}