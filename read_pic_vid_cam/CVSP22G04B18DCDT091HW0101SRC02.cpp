/*
	Mon hoc:	THI GIAC MAY TINH
	Nhom:		04
	Ho ten:		NGUYEN HUY HUNG
	MSV:		B18DCDT091
	Email:		nhuyhung146@gmail.com
*/

// Import gói thư viện
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
// dùng namespace để không phải khai báo "namespace::function()" lại nhiều lần
using namespace std;
using namespace cv;

int main() {
	// Tạo ra một cửa sổ "Demo2" 
	namedWindow("Demo2", WINDOW_AUTOSIZE); 
	// WINDOW_AUTOSIZE kích cỡ cửa sổ tạo ra tự động tùy thuộc vào kích thước của ảnh/video
	// Tạo Object chứa video
	VideoCapture cap;
	// Đọc video từ file
	cap.open("D:/VS_Projects/Resources/cat.mp4");
	// Báo lỗi khi video không hợp lệ
	if (!cap.isOpened()) {
		return -1;
	}
	// Tạo Object để lưu video
	VideoWriter video("D:/VS_Projects/Resources/demo2.mp4", VideoWriter::fourcc('a', 'v', 'i', '4'), 15 ,Size(720, 480));
	// Syntax VideoWriter(tên, chuẩn mã hóa, fps, kích thước khung hình)

	Mat frame;
	// Vòng lặp đọc, hiển thị, lưu cho đến kết thục video
	while(1) {
		// Hiển thị video Frame by Frame
		cap >> frame;
		if (frame.empty()) break;
		// Hiển thị Frame
		imshow("Demo2", frame);
		// Lưu video
		video.write(frame);
		// Delay 25ms
		char c = (char)waitKey(25);
		// Nhấn ESC để thoát
		if (c == 27) break;
	}
	return 0;
}