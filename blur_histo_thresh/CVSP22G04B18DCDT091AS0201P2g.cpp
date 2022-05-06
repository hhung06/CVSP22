#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	Mat src = imread("B18DCDT091BSData/no_violent.jpg");

	int morph_size = 2;

	Mat element = getStructuringElement(
		MORPH_RECT,
		Size(2 * morph_size + 1, 2 * morph_size + 1),
		Point(morph_size, morph_size));

	Mat dst;
	morphologyEx(src, dst, MORPH_BLACKHAT, element, Point(-1,-1), 1, 0);

	imshow("Result", dst);

	waitKey(0);

	return 0;
}