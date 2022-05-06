#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	Mat src = imread("B18DCDT091BSData/no_violent.jpg", 0);
	Mat dst1, dst2;
	threshold(src, dst1, 150, 255, 4);
	adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 9, 10);

	imshow("Thresholding", dst1);
	imshow("Adaptive Thresholding", dst2);

	waitKey(0);

	return 0;
}