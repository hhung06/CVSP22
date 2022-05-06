/*
	Mon hoc:	THI GIAC MAY TINH
	Nhom:		04
	Ho ten:		NGUYEN HUY HUNG
	MSV:		B18DCDT091
	Email:		nhuyhung146@gmail.com
*/

// Import gói thư viện
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
// Dùng namespace để không phải khai báo "namespace::function()" lại nhiều lần
using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	// Tạo cửa sổ để hiển thị video thu từ Webcam
	namedWindow("Demo3", WINDOW_AUTOSIZE);
	// Object chứa video từ Webcam
	VideoCapture cap;
	// Đọc video thu được từ Webcam
	cap.open(0);
	if (!cap.isOpened()) return -1;
	// Object để lưu video
	VideoWriter video("D:/VS_Projects/Resources/demo3.mp4", VideoWriter::fourcc('a', 'v', 'i', '4'), 10, Size(680, 480));
	
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