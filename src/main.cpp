#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>

int main(int argc, char** argv) {
    std::cout << "this is a test" << std::endl;

    // Create Img with a uniform background color
    cv::Mat img(500,500, CV_8UC3, cv::Scalar(255,255,255));

    // Draw line from p1 to p2 on Mat img
    cv::Point p1(100,100), p2(200,100);
    cv::Scalar colorLine(0,255,0);
    int thicknessLine = 2;
    cv::line(img, p1, p2, colorLine, thicknessLine);

    // Display the image until click
    cv::imshow("L-System", img);
    cv::waitKey(0);

    return EXIT_SUCCESS;
} 