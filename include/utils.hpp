#pragma once

#include <cmath>

#include "point.hpp"
#include "utils.hpp"

namespace utils {
    double get_length(Point v);

    double dot_product(Point v1, Point v2);

    double cross_product(Point v1, Point v2);

    double get_angle(Point v1, Point v2);

    Point get_rotated_direction(Point direction, double angle);

    Point convert_to_point(Point point);
};