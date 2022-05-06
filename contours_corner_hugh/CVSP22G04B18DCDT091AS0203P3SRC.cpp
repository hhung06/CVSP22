#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"


using namespace cv;
using namespace std;

int main()
{
    // Khai báo đầu ra
    Mat op1, op2, std_op, prob_op;
    // Đọc file ảnh gốc
    Mat src = imread("src/shape.png");
    Mat temp = src.clone();

    // Phát hiện cạnh phương pháp Canny
    Canny(src, op1, 100, 200, 3);

    cvtColor(op1, std_op, COLOR_GRAY2BGR);
    prob_op = std_op.clone();

    // Làm mờ
    cvtColor(temp, op2, COLOR_BGR2GRAY);
    medianBlur(op2, op2, 5);

    // Standard Hough Line Transform
    vector<Vec2f> lines;
    HoughLines(op1, lines, 1, CV_PI / 180, 150, 0, 0);
    // Vẽ các đường thẳng
    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        line(std_op, pt1, pt2, Scalar(0, 0, 255), 2, 8);
    }

    // Probabilistic Hough Line Transform
    vector<Vec4i> linesP;
    HoughLinesP(op1, linesP, 1, CV_PI / 180, 50, 50, 10);
    // Vẽ đường thằng
    for (size_t i = 0; i < linesP.size(); i++)
    {
        Vec4i l = linesP[i];
        line(prob_op, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, 8);
    }

    // Hough Circle Transform
    vector<Vec3f> circles;
    HoughCircles(op2, circles, HOUGH_GRADIENT, 1,
        op2.rows / 16,  // change this value to detect circles with different distances to each other
        100, 30, 30, 100 // change the last two parameters
   // (min_radius & max_radius) to detect larger circles
    );
    for (size_t i = 0; i < circles.size(); i++)
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // circle center
        circle(temp, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
        // circle outline
        int radius = c[2];
        circle(temp, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
    }



    // Hiển thị kết quả
    imshow("Source", src);
    imshow("Detected Lines (in red) - Standard Hough Line Transform", std_op);
    imshow("Detected Lines (in red) - Probabilistic Line Transform", prob_op);
    imshow("Detected circles", temp);
    
    // Wait and Exit
    waitKey();
    return 0;
}