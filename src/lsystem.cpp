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
    int width = 800;
    int height = 800;
    cv::Mat img(width, height, CV_8UC3, cv::Scalar(255, 255, 255));

    // Line properties
    cv::Scalar colorLine(0, 255, 0);
    int thicknessLine = 2;

    cv::Point2d start_point(width/2, height);
    cv::Point2d direction(0, 1);
    double length{10};
    std::vector<cv::Point2d> positions;
    std::vector<cv::Point2d> directions;

    // Specific for the example 2 of Wikipedia
    cv::Point2d last_point = start_point;
    cv::Point2d last_direction = direction;

    cv::Point2d new_point;
    for (char cursor : production) {
        switch (cursor) {
            case '0':
                new_point.x = last_point.x + (last_direction.x * length);
                new_point.y = last_point.y - (last_direction.y * length);

                cv::line(img, last_point, new_point, colorLine, thicknessLine);
                break;
            case '1':
                new_point.x = last_point.x + (last_direction.x * length);
                new_point.y = last_point.y - (last_direction.y * length);

                cv::line(img, last_point, new_point, colorLine, thicknessLine);
                last_point = new_point;
                break;
            case '[':
                positions.push_back(last_point);
                directions.push_back(last_direction);
                last_direction = get_rotated_direction(last_direction, M_PI/4);
                break;
            case ']':
                last_direction = get_rotated_direction(directions.back(), -1 * M_PI/4);
                last_point = positions.back();
                positions.pop_back();
                directions.pop_back();
                break;
        }
    }

    // Display the image until click
    cv::imshow("L-System", img);
    cv::waitKey(0);
}