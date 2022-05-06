/*
	Mon hoc:	THI GIAC MAY TINH
	Nhom:		04
	Ho ten:		NGUYEN HUY HUNG
	MSV:		B18DCDT091
	Email:		nhuyhung146@gmail.com
*/

//Khai báo thư viện
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
//Khai báo namespace
using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	//Tạo cửa sổ Webcam
	namedWindow("Webcam", WINDOW_AUTOSIZE);
	//Tạo object chứa video lấy từ Webcam
	VideoCapture cap;
	//Đọc video lấy từ Webcam
	cap.open(0);
	if (!cap.isOpened()) return -1;
	//Tạo ma trận chứa khung hình
	Mat frame;
	//Biến đếm
	int tmp = 0;
	//Thiết lập tên file
	string Emotion = "B18DCDT091E", Finger = "B18DCDT091F", filesuffix = ".png";
	//Vòng lặp
	for (;;) {
		// Hiển thi video theo từng frame
		cap >> frame;
		//
		if (frame.empty()) break;
		imshow("Webcam", frame);
		
		//Thiết lập phím tắt delay 10ms
		char c = (char)waitKey(10);

		if (c == 'e') { //Nhấn E để lưu các ảnh chứa cảm xúc
			tmp++; //Mỗi lần nhấn biến đếm sẽ tăng
			//Tên file giá trị bằng biến đếm chuyển sang string + tên + định dạng
			string filenameE = to_string(tmp) + Emotion + filesuffix;
			//Lưu ảnh
			imwrite("B18DCDT091EData/0" + filenameE, frame);
		}
		if (c == 'f') { //NHấn F để lưu các ảnh chứa ngón tay
			tmp++;
			string filenameF = to_string(tmp) + Finger + filesuffix;
			imwrite("B18DCDT091FData/" + filenameF, frame);
		}
		if (c == 27) break; //Nhấn ESC để thoát
	}
	return 0;
}