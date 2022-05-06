#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	Mat src = imread("B18DCDT091BSData/no_violent.jpg", 0);
	Mat dst;
	equalizeHist(src, dst);

	imshow("Equalized", dst);

	waitKey(0);

	return 0;
}