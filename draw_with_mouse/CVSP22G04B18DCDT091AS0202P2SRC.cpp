//Khai báo thư viện
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
//Khai báo namespace
using namespace std;
using namespace cv;

Mat img, result;

void mouse_draw(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {

		Mat mask = Mat::zeros(Size(img.cols, img.rows), CV_8UC1);

		circle(mask, Point(x, y), 100, Scalar(255, 255, 255), -1);

		imshow("Mask", mask);

		bitwise_and(img, img, result, mask);

		imshow("result", result);
	}
}

int main(int argc, char** argv) {
	//Đọc ảnh
	img = imread("B18DCDT091BSData/no_violent.jpg");

	namedWindow("Original");
	//Hiển thị ảnh gốc
	imshow("Original", img);
	//Gọi hàm setMouseCallback trên cửa sổ ảnh gốc
	setMouseCallback("Original", mouse_draw);
	//Đợi cho đến khi nhấn ESC để thoát

	while (char(waitKey(10) != 27)) {

	}
	return 0;
}