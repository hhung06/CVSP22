#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img;

void countours_demo() {
	Mat canny_output;
	Canny(img, canny_output, 100, 200);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	
	// Hull
	vector<vector<Point> >hull(contours.size());
	
	// Box & Circle
	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	vector<Point2f>centers(contours.size());
	vector<float>radius(contours.size());
	
	// minArea
	vector<RotatedRect> minRect(contours.size());
	vector<RotatedRect> minEllipse(contours.size());


	for (size_t i = 0; i < contours.size(); i++)
	{
		// Hull
		convexHull(contours[i], hull[i]);

		// Box & Circle
		approxPolyDP(contours[i], contours_poly[i], 3, true);
		boundRect[i] = boundingRect(contours_poly[i]);
		minEnclosingCircle(contours_poly[i], centers[i], radius[i]);

		// minArea
		minRect[i] = minAreaRect(contours[i]);
		if (contours[i].size() > 5)
		{
			minEllipse[i] = fitEllipse(contours[i]);
		}

	}

	Mat out1, out2, out3, out4;
	out1 = Mat::zeros(canny_output.size(), CV_8SC3);
	out2 = Mat::zeros(canny_output.size(), CV_8SC3);
	out3 = Mat::zeros(canny_output.size(), CV_8SC3);
	out4 = Mat::zeros(canny_output.size(), CV_8SC3);
	
	for (size_t i = 0; i < contours.size(); i++)
	{
		drawContours(out1, contours, (int)i, Scalar(255, 255, 255), 1, 8, hierarchy, 0);
		
		// Hull
		drawContours(out2, contours, (int)i, Scalar(255,255,255)); // white color for countours
		drawContours(out2, hull, (int)i, Scalar(0,255,0)); // green color for convexhull

		// Box & Circle
		drawContours(out3, contours_poly, (int)i, Scalar(255, 255, 255));
		rectangle(out3, boundRect[i].tl(), boundRect[i].br(), Scalar(128, 0, 128), 1);
		circle(out3, centers[i], (int)radius[i], Scalar(71, 99, 255), 1);

		// ellipse
		ellipse(out4, minEllipse[i], Scalar(0, 165, 255), 1);
		// rotated rectangle
		Point2f rect_points[4];
		minRect[i].points(rect_points);
		for (int j = 0; j < 4; j++)
		{
			drawContours(out4, contours, (int)i, Scalar(255,255,255));
			line(out4, rect_points[j], rect_points[(j + 1) % 4], Scalar(255, 255, 0));
		}
	}
	imshow("Contours", out1);

	imshow("Hull", out2);

	imshow("Box & Circle", out3);

	imshow("minArea", out4);
}


int main() {
	img = imread("src/seeds.png",0);
	GaussianBlur(img, img, Size(5, 5), 0);

	imshow("Blured", img);

	countours_demo;
	
	while (char(waitKey(10) != 27)) {}

	return 0;
}