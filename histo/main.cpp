#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "opencv2/core/utility.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

const char* keys=
{
	"{help h usage ? | | gui adding buttons drawing histograms and other things}"
	"{@image | | image to be processed}"
};

Mat img; string imageFile;
void ShowHistCallback(int, void * );
void EqualizeCallback(int, void * );
void LomoCallback	 (int, void * );
void CartoonCallback (int, void * );

int main(int argc, const char** argv)
{
	CommandLineParser Parser(argc,argv,keys);
	Parser.about("Histograms");

	if(Parser.has("help"))
	{
		Parser.printMessage();
		return 0;
	}

	imageFile=Parser.get<string>(0);

	if(!Parser.check())
	{
		Parser.printErrors();
		return 0;
	}

	Mat img= imread(imageFile);
	if(img.empty()) { cout<<"\ncannot load image..!"<<endl; return 0; }

	namedWindow("Picasa");

	createButton("Show Histogram",ShowHistCallback,&img,QT_PUSH_BUTTON,0);
	createButton("Equalize histogram",EqualizeCallback,NULL,QT_PUSH_BUTTON,0);
	createButton("Lomography effect",LomoCallback,NULL,QT_PUSH_BUTTON,0);
	createButton("Cartoonize effect",CartoonCallback,NULL,QT_PUSH_BUTTON,0);
	
	imshow("Picasa",img);
	waitKey(0);
	return 0;
}

void ShowHistCallback(int state, void *userdata)
{	
	//img= imread(imageFile);
	Mat img= *((Mat*)userdata);
	if(img.empty()) cout<<"\ncannot load image..!"<<endl;
	
	Mat bgr[3];
	
	split(img,bgr);

	int nofbins=256;

	float range[]={0,256};
	const float *histRange={range};

	Mat b_hist,g_hist,r_hist;

	calcHist(&bgr[0],1,0,Mat(),b_hist,1,&nofbins,&histRange,true);
	calcHist(&bgr[1],1,0,Mat(),g_hist,1,&nofbins,&histRange,true);
	calcHist(&bgr[2],1,0,Mat(),r_hist,1,&nofbins,&histRange,true);

	int width=512;
	int height=300;

	Mat histImage(height,width,CV_8UC3, Scalar(20,20,20));

	normalize(b_hist,b_hist,0,height, NORM_MINMAX);
	normalize(g_hist,g_hist,0,height, NORM_MINMAX);
	normalize(r_hist,r_hist,0,height, NORM_MINMAX);

	int binStep=cvRound((float) width/(float) nofbins);

	for( int i=1; i< nofbins; i++)
	{
		line( histImage,Point( binStep*(i-1), height-cvRound(b_hist.at<float>(i-1) )),Point( binStep*(i), height-cvRound(b_hist.at<float>(i) )),Scalar(255,0,0));
		line( histImage,Point( binStep*(i-1), height-cvRound(g_hist.at<float>(i-1) )),Point( binStep*(i), height-cvRound(g_hist.at<float>(i) )),Scalar(0,255,0));
		line( histImage,Point( binStep*(i-1), height-cvRound(r_hist.at<float>(i-1) )),Point( binStep*(i), height-cvRound(r_hist.at<float>(i) )),Scalar(0,0,255));
	}
	namedWindow("Histogram");
	imshow("Histogram", histImage);
	waitKey(0);
}

void EqualizeCallback(int state, void * userData)
{

}

void LomoCallback(int state, void * userData)
{

}

void CartoonCallback(int state, void * userData)
{

}
