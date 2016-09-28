#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
//const int CV_GUI_NORMAL= 0x10;

int main( int argc, const char** argv )
{
	// Read images
	Mat lana= imread("lana.jpeg");
	Mat photo= imread("photo.jpeg");
	// Create windows
	namedWindow("Lana", CV_GUI_NORMAL);
	namedWindow("Photo", WINDOW_AUTOSIZE);
	// Move window
	moveWindow("Lana", 10, 10);
	moveWindow("Photo", 1000, 10);
	// show images
	imshow("Lana", lana);
	imshow("Photo", photo);

	waitKey(0);
	// Resize window, only non autosize
	resizeWindow("Lana", 512, 512);
	// wait for any key press
	waitKey(0);

	// Destroy the windows
	destroyWindow("Lana");
	destroyWindow("Photo");
	// Create 10 windows
	for(int i =0; i< 10; i++)
	{
		ostringstream ss;
		ss << "Photo " << i;
		namedWindow(ss.str());
		moveWindow(ss.str(), 20*i, 20*i);
		imshow(ss.str(), photo);
	}
	waitKey(0);
								// Destroy all windows
	destroyAllWindows();
	return 0;
}