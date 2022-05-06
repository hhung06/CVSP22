//Khai báo thư viện
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>

//Khai báo namespace
using namespace std;
using namespace cv;

//Ma trận chứa ảnh nguồn
Mat img;

Point corner1, corner2;

void mouse_draw(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDBLCLK) {
		corner1 = Point(x, y);
		Mat tmp_img = img.clone();
		circle(tmp_img, corner1, 100, Scalar(255, 255, 0), 3, 8, 0);
		imshow("Original", tmp_img);
	}

	if (event == EVENT_RBUTTONDBLCLK) {
		corner1 = Point(x, y);
		Mat tmp_img = img.clone();
		putText(tmp_img,"Hello", corner1, FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 0), 3, 8);
		imshow("Original", tmp_img);
	}

	if (event == EVENT_RBUTTONDOWN) {
		corner1 = Point(x, y);
		Mat tmp_img = img.clone();
		ellipse(tmp_img, corner1, Size(40, 100), 90, 0, 360, Scalar(255, 255, 0), 3);
		imshow("Original", tmp_img);
	}

	if (event == EVENT_MBUTTONDOWN) {
		corner1 = Point(x, y);
		Mat tmp_img = img.clone();
		rectangle(tmp_img, corner1, Point(corner1.x + 100, corner1.y + 150), Scalar(0, 0, 255), 3);
		imshow("Original", tmp_img);
	}

	if (event == EVENT_MBUTTONDBLCLK) {
		corner1 = Point(x, y);
		Mat tmp_img = img.clone();
		line(tmp_img, corner1, Point(0, corner1.y + 150), Scalar(0, 0, 255), 3);
		imshow("Original", tmp_img);
	}
}

int main(int argc, char** argv) {
	//Đọc ảnh
	img = imread("B18DCDT091BSData/no_violent.jpg");
	//Cửa sổ ảnh gốc
	namedWindow("Original");

	imshow("Original", img);
	//Gọi hàm setMouseCallback trên cửa sổ ảnh gốc
	setMouseCallback("Original", mouse_draw);
	//Đợi cho đến khi nhấn ESC để thoát
	while (char(waitKey(10) != 27)) {

	}
	return 0;
}
