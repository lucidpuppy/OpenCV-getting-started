#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;


int main(int argc, const char** argv)
{
	Mat color=imread("lana.jpeg");
	Mat grey=imread("lana.jpeg",0);

	if(color.empty()|| grey.empty())
	{
		cout<<"\nCan't print..image not found\n";
		return -1;
	}

	imwrite("color.jpeg", color);
	waitKey(2000);
	imwrite("grey.jpeg", grey);

	int width= color.cols -1;
	int height= color.rows -1;

	cout<<"\nwidth equals:"<<width<<" and height equals:"<<height;

	Vec3b pixel= color.at<Vec3b>(135,190);
	cout<<"\nBGR value at 135,150 equals: "<<(int)pixel[0]<<" "<<(int)pixel[1]<<" "<<(int)pixel[2];
	cout<<("\n");
}