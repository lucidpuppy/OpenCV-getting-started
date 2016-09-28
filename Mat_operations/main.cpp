#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;


int main(int argc, const char** argv)
{
	Mat jack= Mat :: zeros(2,2,CV_32F);
	Mat fell= Mat :: ones(2,2,CV_32F);
	Mat inaPond= Mat :: eye(2,2,CV_32F);			//Identity mat

	cout<<jack<<endl;

	cout<<fell<<endl;

	cout<<inaPond<<endl;

	cout<<8*(fell + inaPond)<<endl;

	cout<<(jack) .mul (fell)<<endl;					//. multiplication..element gets multiplied to element

	cout<<(2*fell) * (fell)<<endl;

	FileStorage fs("test.yaml", FileStorage::WRITE);
	
	fs<<"jack"<<jack;
	fs<<"fell"<<fell<<"inaPond"<<inaPond;
	fs.release();

	Mat JackFellinaPond;

	FileStorage fs2("test.yaml", FileStorage ::READ);

	fs2["fell"]>>JackFellinaPond;					//reads from file

	cout<<JackFellinaPond;

	fs2.release();
}