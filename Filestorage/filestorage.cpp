#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;


int main(int argc, const char** argv)
{
	FileStorage fs("cheese.yml",FileStorage::WRITE);
	
	uint8_t fps=60;

	fs<<"fps"<<fps;

	fs.release();
	return 0;
}