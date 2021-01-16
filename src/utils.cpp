#include "utils.hpp"

#include <cmath>

namespace utils {
    double get_length(cv::Point2d v) {
        double length = sqrt(pow(v.x, 2) + pow(v.y, 2));
        return length;
    }

    double dot_product(cv::Point2d v1, cv::Point2d v2) {
        double product = v1.x * v2.x + v1.y * v2.y;
        return product;
    }

    double cross_product(cv::Point2d v1, cv::Point2d v2) {
        double product = (double)(1000 * v1.x * 1000 * v2.y) - (double)(1000 * v1.y * 1000 * v2.x);
        return product;
    }

    double get_angle(cv::Point2d v1, cv::Point2d v2) {
        double dist_v1, dist_v2;
        dist_v1 = get_length(v1);
        dist_v2 = get_length(v2);
        double angle = 0;
        if ((dist_v1 != 0) && (dist_v2 != 0)) {
            angle = acos(
                dot_product(v1, v2) / (get_length(v1) * get_length(v2)));
        }
        return angle;
    }

    cv::Point2d get_rotated_direction(cv::Point2d direction, double angle) {
        cv::Point2d rotated_direction;
        rotated_direction.x = direction.x * cos(angle) - direction.y * sin(angle);
        rotated_direction.y = direction.x * sin(angle) + direction.y * cos(angle);
        return rotated_direction;
    }

    cv::Point convert_to_point(cv::Point2d point) {
        cv::Point new_point{
            static_cast<int>(point.x),
            static_cast<int>(point.y)};
        return new_point;
    }
}
