#include "fractal_binary_tree.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

#include "utils.hpp"

FractalBinaryTree::FractalBinaryTree() {
    this->variables = {"0", "1"};
    this->constants = {"[", "]"};
    this->axiom = "0";
    this->rules.insert({"1", "11"});
    this->rules.insert({"0", "1[0]0"});
    this->recursions = 5;
    this->name = "Fractal Binary Tree";
}

std::vector<std::pair<cv::Point2d, cv::Point2d>> FractalBinaryTree::get_lines() {
    std::vector<std::pair<cv::Point2d, cv::Point2d>> lines;
    auto production = this->produce();
    int width = 800;
    int height = 800;

    cv::Point2d start_point(width / 2, height);
    cv::Point2d direction(0, 1);
    double length{5};
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
                lines.push_back({last_point, new_point});
                break;
            case '1':
                new_point.x = last_point.x + (last_direction.x * length);
                new_point.y = last_point.y - (last_direction.y * length);

                lines.push_back({last_point, new_point});
                last_point = new_point;
                break;
            case '[':
                positions.push_back(last_point);
                directions.push_back(last_direction);
                last_direction = utils::get_rotated_direction(last_direction, M_PI / 4);
                break;
            case ']':
                last_direction = utils::get_rotated_direction(directions.back(), -1 * M_PI / 4);
                last_point = positions.back();
                positions.pop_back();
                directions.pop_back();
                break;
        }
    }

    return lines;
}
