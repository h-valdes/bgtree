#pragma once

#include <cmath>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

#include "utils.hpp"

namespace utils {
    double get_length(cv::Point2d v);

    double dot_product(cv::Point2d v1, cv::Point2d v2);

    double cross_product(cv::Point2d v1, cv::Point2d v2);

    double get_angle(cv::Point2d v1, cv::Point2d v2);

    cv::Point2d get_rotated_direction(cv::Point2d direction, double angle);

    cv::Point convert_to_point(cv::Point2d point);
};