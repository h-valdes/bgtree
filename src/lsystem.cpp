#include "lsystem.hpp"
#include "utils.hpp"

#include <algorithm>
#include <iostream>
#include <cmath>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

LSystem::LSystem(
    std::vector<std::string> variables,
    std::vector<std::string> constants,
    std::string axiom,
    std::map<std::string, std::string> rules,
    int recursions) {
    this->variables = variables;
    this->constants = constants;
    this->axiom = axiom;
    this->rules = rules;
    this->recursions = recursions;
}

std::string LSystem::produce() {
    std::string output = this->axiom;
    std::cout << "n = " << 0 << " : " << output << std::endl;

    for (int n = 1; n < this->recursions; n++) {
        std::string tmp_output = "";
        for (auto cursor_char : output) {
            std::string cursor_str{cursor_char};
            if (std::find(this->constants.begin(), this->constants.end(), cursor_str) != this->constants.end()) {
                tmp_output += cursor_str;
            } else {
                tmp_output += this->rules.at(cursor_str);
            }
        }

        std::cout << "n = " << n << " : " << tmp_output << std::endl;
        output = tmp_output;
    }

    return output;
}

void LSystem::draw() {
    auto production = this->produce();
    int width = 500;
    int height = 500;
    cv::Mat img(width, height, CV_8UC3, cv::Scalar(255, 255, 255));

    // Line properties
    cv::Scalar colorLine(0, 255, 0);
    int thicknessLine = 1;

    cv::Point2d start_point(width/2, height);
    cv::Point2d direction(0, 1);
    double length{10};
    std::vector<cv::Point2d> positions;

    // Specific for the example 2 of Wikipedia
    cv::Point2d tmp_point = start_point;
    for (char cursor : production) {
        switch (cursor) {
            case '0':
                break;
            case '1':
                break;
            case '[':
                positions.push_back(tmp_point);
                break;
            case ']':
                positions.pop_back();
                break;
        }
    }

    // Draw line from p1 to p2 on Mat img
    cv::Point p1(100, 100);
    cv::line(img, p1, start_point, colorLine, thicknessLine);

    // Display the image until click
    cv::imshow("L-System", img);
    cv::waitKey(0);
}