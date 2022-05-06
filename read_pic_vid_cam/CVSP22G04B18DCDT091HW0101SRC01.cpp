/*
	Mon hoc:	THI GIAC MAY TINH
	Nhom:		04
	Ho ten:		NGUYEN HUY HUNG
	MSV:		B18DCDT091
	Email:		nhuyhung146@gmail.com
*/

// Import gói thư viện
#include <iostream>
#include <opencv2/opencv.hpp>
// dùng namespace để không phải khai báo "namespace::function()" lại nhiều lần
using namespace std;
using namespace cv;

int main() {
	// Đọc một ảnh và lưu vào biến img
	Mat img = imread("D:/VS_Projects/Resources/hung.jpg");
	// Báo lỗi nếu không có ảnh
	if (img.empty()) return -1;
	// Hiển thị ảnh
	imshow("demo1", img);
	// Lưu ảnh
	imwrite("D:/VS_Projects/Resources/demo1.png", img);
	// Đợi cho đến khi có một phím được bấm vào trong khoảng thời gian delay (ms).
	waitKey(0); // Nếu muốn dừng lại màn hình mãi thì để 0
	return 0;
}
