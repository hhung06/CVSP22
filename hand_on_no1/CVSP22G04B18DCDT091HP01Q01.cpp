#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat src, gray_img, hsv_img;

int main() {
	Mat src = imread("src/hung.jpg");
	cvtColor(src, gray_img, COLOR_BGR2GRAY);
	cvtColor(src, hsv_img, COLOR_BGR2HSV);

	imshow("Original", src);
	imshow("Gray", gray_img);
	imshow("HSV", hsv_img);

	waitKey(0);
	return 0;
}