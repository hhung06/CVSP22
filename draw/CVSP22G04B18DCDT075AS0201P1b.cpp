#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

void main()
	{
		Mat img(320, 480, CV_8UC3, Scalar(0, 255, 255));

		rectangle(img, Rect(100, 0, 50, 250), Scalar(255, 0, 0), -1);
		rectangle(img, Rect(0, 100, 250, 50), Scalar(255, 0, 0), -1);

		imshow("Image", img);

		waitKey(0);

		return 0;
	}