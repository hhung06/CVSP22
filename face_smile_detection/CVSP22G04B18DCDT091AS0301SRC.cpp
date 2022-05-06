#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {

	//CascadeClassifier faceCascade;
	//faceCascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalcatface_extended.xml");
	
	CascadeClassifier smileCascade;
	smileCascade.load("C:/opencv/sources/data/haarcascades/haarcascade_smile.xml");

	namedWindow("Webcam", WINDOW_AUTOSIZE);
	
	VideoCapture cap;
	
	cap.open(0);
	if (!cap.isOpened()) return -1;

	if (smileCascade.empty()) {
		cout << "Failed to load the xml" << endl;
		return -1;
	}
	else cout << "Load xml file successfully" << endl;

	Mat frame;

	vector<Rect> faces;
	vector<Rect> smiles;


	while (1) {
		cap >> frame;

		if (frame.empty()) break;

		//faceCascade.detectMultiScale(frame, faces);
		smileCascade.detectMultiScale(frame, smiles, 1.3, 10);
		
		//for (int i = 0; i < faces.size(); i++) {
		for (int j = 0; j < smiles.size(); j++) {
			//rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(255, 0, 0), 3);
			rectangle(frame, smiles[j].tl(), smiles[j].br(), Scalar(255, 0, 0), 3);
			imwrite("src/smileface.jpg", frame);
		}
		//}

		imshow("Webcam", frame);

		char c = (char)waitKey(10);

		if (c == 27) break;
	}
	return 0;
}