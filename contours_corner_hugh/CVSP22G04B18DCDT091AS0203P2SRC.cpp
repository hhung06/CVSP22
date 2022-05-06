#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img;
int thresh = 200;
int max_thresh = 255;

void cornerHarris_demo(int, void*) {
	int blockSize = 2;
	int apertureSize = 3;
	double k = 0.04;

	Mat dst = Mat::zeros(img.size(), CV_32FC1);
	cornerHarris(img, dst, blockSize, apertureSize, k);

    Mat dst_norm, dst_norm_scaled;
    normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(dst_norm, dst_norm_scaled);
    for (int i = 0; i < dst_norm.rows; i++)
    {
        for (int j = 0; j < dst_norm.cols; j++)
        {
            if ((int)dst_norm.at<float>(i, j) > thresh)
            {
                circle(dst_norm_scaled, Point(j, i), 5, Scalar(0), 2, 8, 0);
            }
        }
    }

    imshow("corners", dst_norm_scaled);
}

int main() {
    img = imread("src/logo.jpg",0);

    namedWindow("source");
    imshow("source", img);

    createTrackbar("Threshold: ", "source", &thresh, max_thresh, cornerHarris_demo);
    cornerHarris_demo(0,0);

    waitKey(0);
    return 0;
}