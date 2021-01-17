#include "fractal_plant.hpp"

#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

#include "utils.hpp"

FractalPlant::FractalPlant() {
    this->variables = {"X", "F"};
    this->constants = {"+", "-", "[", "]"};
    this->axiom = "X";
    this->rules.insert({"X", "F+[[X]-X]-F[-FX]+X"});
    this->rules.insert({"F", "FF"});
    this->recursions = 6;
    this->angle = M_PI / 8;
    this->name = "Fractal Plant";
}

std::vector<std::pair<cv::Point2d, cv::Point2d>> FractalPlant::get_lines() {
    std::vector<std::pair<cv::Point2d, cv::Point2d>> lines;
    auto production = this->produce();
    int width = 800;
    int height = 800;

    cv::Point2d start_point(width / 2, height);
    cv::Point2d direction(0, 1);
    double length{4.5};
    std::vector<cv::Point2d> positions;
    std::vector<cv::Point2d> directions;

    // Specific for the example 2 of Wikipedia
    cv::Point2d last_point = start_point;
    cv::Point2d last_direction = direction;

    cv::Point2d new_point;
    for (char cursor : production) {
        switch (cursor) {
            case 'X':
                break;
            case '-':
                last_direction = utils::get_rotated_direction(last_direction, -1 * angle);
                break;
            case '+':
                last_direction = utils::get_rotated_direction(last_direction, angle);
                break;
            case 'F':
                new_point.x = last_point.x + (last_direction.x * length);
                new_point.y = last_point.y - (last_direction.y * length);
                lines.push_back({last_point, new_point});
                last_point = new_point;
                break;
            case '[':
                positions.push_back(last_point);
                directions.push_back(last_direction);
                break;
            case ']':
                last_direction = directions.back();
                last_point = positions.back();
                positions.pop_back();
                directions.pop_back();
                break;
        }
    }

    return lines;
}
