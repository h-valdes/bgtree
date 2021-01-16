#include "lsystem.hpp"

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>

LSystem::LSystem() {
    this->variables = {"A", "B"};
    this->axiom = "A";
    this->rules.insert({"A", "AB"});
    this->rules.insert({"B", "A"});
}

void LSystem::produce() {
    std::string output = this->axiom;
    std::cout << "n = " << 0 << " : " << output << std::endl;
    
    for (int n = 1; n < 8; n++) {
        std::string tmp_output = "";
        for (auto variable_char : output) {
            std::string variable_str{variable_char};
            tmp_output += this->rules.at(variable_str);
        }

        std::cout << "n = " << n << " : " << tmp_output << std::endl;
        output = tmp_output;
    }
}

void LSystem::draw() {
    this->produce();

    // Create Img with a uniform background color
    cv::Mat img(500, 500, CV_8UC3, cv::Scalar(255, 255, 255));

    // Draw line from p1 to p2 on Mat img
    cv::Point p1(100, 100), p2(200, 100);
    cv::Scalar colorLine(0, 255, 0);
    int thicknessLine = 1;
    cv::line(img, p1, p2, colorLine, thicknessLine);

    // Display the image until click
    cv::imshow("L-System", img);
    cv::waitKey(0);
}