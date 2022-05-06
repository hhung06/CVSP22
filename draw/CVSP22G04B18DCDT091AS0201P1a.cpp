#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat img(320, 480, CV_8UC3, Scalar(0, 255, 255));
	imshow("Yellow", img);
	waitKey(0);
	return 0;
}