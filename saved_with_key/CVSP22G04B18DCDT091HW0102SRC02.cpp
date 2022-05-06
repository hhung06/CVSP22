/*
	Mon hoc:	THI GIAC MAY TINH
	Nhom:		04
	Ho ten:		NGUYEN HUY HUNG
	MSV:		B18DCDT091
	Email:		nhuyhung146@gmail.com
*/

//Khai báo thư viện
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
//Khai báo namespace
using namespace std;
using namespace cv;
//Khởi tạo các biến tương tự cho trạng thái của chuột trái
bool leftDown = false, leftUp = false;
//Ma trận chứa ảnh nguồn
Mat img;
//Tạo khung hình chứa vùng cắt
Rect box;
//Biến chứa tọa độ 2 góc chéo nhau của vùng muốn cắt
Point corner1, corner2;
//Hàm cắt bằng chuột
void mouse_crop(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) { //Chuột trái ở trạng thái NHẤN
		leftDown = true;
		corner1 = Point(x, y); //Tọa độ góc = tọa độ chuột 
	}
	if (event == EVENT_LBUTTONUP) { //Chuột trái ở trạng thái THẢ
		leftUp = true;
		corner2 = Point(x, y);
	}
	if (leftDown==true&&leftUp==false){ // Khi NHẤN chuột trái
		Point pt;
		pt = Point(x, y);
		Mat tmp_img = img.clone();
		//Vẽ hình chữ nhật trên bản sao của ảnh gốc
		//Tọa độ điểm bắt đầu = tọa độ chuột từ lúc bắt đầu NHẤN
		//Tọa độ điểm kết thúc = tọa độ cuối cùng của chuột ở trạng thái NHẤN
		rectangle(tmp_img, corner1, pt, Scalar(0, 0, 255));
		//Hiển thị bản sao với hình chữ nhật được vẽ ở trên
		imshow("Original", tmp_img);
	}
	//Quá trình lựa chọn vùng cắt kết thúc, hai trạng thái NHẤN THẢ chuột đã diễn ra
	if (leftDown == true && leftUp == true) {
		box.width = abs(corner1.x - corner2.x); //Chiều rộng của khung
		box.height = abs(corner1.y - corner2.y); //Chiều dài khung
		//Tọa độ x,y góc trái trên của khung sẽ = x,y nhỏ nhất trong hai góc
		box.x = min(corner1.x, corner2.x);
		box.y = min(corner1.y, corner2.y);
		//Ma trận chứa vùng cắt
		Mat crop(img, box);
		//Tên cửa sổ vùng cắt
		namedWindow("Cropped");
		//Hiển thị vùng cắt
		imshow("Cropped", crop);
		//Lưu ảnh chứa vùng cắt
		imwrite("B18DCDT091BSData/02.jpg", crop);

		leftDown = false;
		leftUp = false;
	}
}

int main(int argc, char** argv) {
	//Đọc ảnh
	img = imread("src/violent.jpg");
	//Cửa sổ ảnh gốc
	namedWindow("Original");
	//Hiển thị ảnh gốc
	imshow("Original", img);
	//Gọi hàm setMouseCallback trên cửa sổ ảnh gốc
	setMouseCallback("Original", mouse_crop);
	//Đợi cho đến khi nhấn ESC để thoát
	while (char(waitKey(10) != 27)) {

	}
	return 0;
}