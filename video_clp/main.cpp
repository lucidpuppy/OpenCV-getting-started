#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

const char* keys =
{
	"{help h usage ? | | print this message}"
	"{@video  | | Video file, if not defined try to use webcamera}"
	"{@image  | | image file}"
};

int main(int argc, const char** argv)
{
	CommandLineParser parser(argc,argv,keys);

	parser.about("CommandLine parser testing..!");

	if(parser.has("help"))
	{
		parser.printMessage();
		return 0;
	}

	String videoFile= parser.get<String>(0);
	
	//String imageFile=parser.get<String>(0);


	if(!parser.check())
	{
		parser.printErrors();
		return 0;
	}

	//Mat img;
	
	VideoCapture vid;

	//if(imageFile !="") img=imread(imageFile);
	//else img=imread("lana.jpeg");

	if(videoFile !="") vid.open(videoFile);
	else vid.open(0);
	
	if(!vid.isOpened()) { cout<<"\nNo video loaded exit."; return -1; }
	
	//if(img.empty()) { cout<<"\nNo image loaded exit."; return -1; }
	
	namedWindow("Video",1);

	for(;;)
	{
		Mat frame;
		vid>> frame;
		imshow("Video",frame);
		if(waitKey(30)>=0) break;
	}

	vid.release();
	destroyWindow("Video");
	
	
	//namedWindow("Image",1);
	//imshow("Image", img);
	//waitKey(2000);

	return 0;
}