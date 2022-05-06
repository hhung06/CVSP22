#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap;
	cap.open("src/sample.mp4");
	if (!cap.isOpened()) {
		return -1;
	}

	Mat frame, hsv_frame, gray_frame;
	while (true) {
		cap >> frame;
		cvtColor(frame, hsv_frame, COLOR_BGR2HSV);
		cvtColor(frame, gray_frame, COLOR_BGR2GRAY);

		if (frame.empty()) break;

		imshow("Original", frame);
		imshow("HSV", hsv_frame);
		imshow("Gray", gray_frame);

		char c = (char)waitKey(25);
		if (c == 27) break;
	}
	return 0;
}