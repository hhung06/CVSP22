#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat src, simple, box, median, gauss, bilateral;

int main(int argc, char** argv) {
	src = imread("B18DCDT091BSData/no_violent.jpg");
	//Simple Blur
	blur(src, simple, Size(3, 3), Point(-1, -1));
	//Box Filter
	boxFilter(src, box, CV_8U, Size(3, 3), Point(-1, -1));
	//Gaussian Filter
	GaussianBlur(src, gauss, Size(3, 3), 0, 0);
	//Median Filter
	medianBlur(src, median, 3);
	//Bilateral Filter
	bilateralFilter(src, bilateral, 3, 1.0, 1.0);

	imshow("Original", src);
	imshow("Simple Blur", simple);
	imshow("Box Filter", box);
	imshow("Gaussian Filter", gauss);
	imshow("Median Filter", median);
	imshow("Bilateral Filter", bilateral);

	waitKey(0);

	return 0;
}