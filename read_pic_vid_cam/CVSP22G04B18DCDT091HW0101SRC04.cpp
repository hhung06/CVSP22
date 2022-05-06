/*
	Mon hoc:	THI GIAC MAY TINH
	Nhom:		04
	Ho ten:		NGUYEN HUY HUNG
	MSV:		B18DCDT091
	Email:		nhuyhung146@gmail.com
*/

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
	namedWindow("Demo4", WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open("http://hung:1234@192.168.1.4:8080/video.cgi?.mjpg"); // Vidu camera ip
	if (!cap.isOpened()) {
		return -1;
	}

	VideoWriter video("D:/VS_Projects/Resources/demo4.mp4", VideoWriter::fourcc('a', 'v', 'i', '4'), 10, Size(680, 480));

	Mat frame;

	while (1) {
		cap >> frame;

		if (frame.empty()) break;
		// Hiển thị
		imshow("Demo3", frame);
		// Delay 25ms
		char c = (char)waitKey(25);
		// Lưu video
		video.write(frame);
		// Nhấn ESC để thoát
		if (c == 27) break;
	}
	return 0;
}