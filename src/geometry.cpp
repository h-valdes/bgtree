#include "geometry.hpp"

#include <cmath>

template<class T>
double get_length(Point<T> v) {
    double length = sqrt(pow(v.x, 2) + pow(v.y, 2));
    return length;
}

template<class T>
double dot_product(Point<T> v1, Point<T> v2) {
    double product = v1.x * v2.x + v1.y * v2.y;
    return product;
}

template<class T>
double cross_product(Point<T> v1, Point<T> v2) {
    double product = (double)(1000 * v1.x * 1000 * v2.y) - (double)(1000 * v1.y * 1000 * v2.x);
    return product;
}

template<class T>
double get_angle(Point<T> v1, Point<T> v2) {
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

template<class T>
Point<T> get_rotated_direction(Point<T> direction, T angle) {
    Point<T> rotated_direction;
    rotated_direction.x = direction.x * cos(angle) - direction.y * sin(angle);
    rotated_direction.y = direction.x * sin(angle) + direction.y * cos(angle);
    return rotated_direction;
}

template<class T>
Point<T> convert_to_point(Point<T> point) {
    Point<T> new_point{
        static_cast<int>(point.x),
        static_cast<int>(point.y)};
    return new_point;
}

Point<double> get_centroid(const std::vector<std::pair<Point<double>, Point<double>>> lines) {
    Point<double> center{0, 0};
    int counter = 0;
    double total_x = 0;
    double total_y = 0;

    for (auto line : lines) {
        total_x += (line.first.x + line.second.x) / 2; 
        total_y += (line.first.y + line.second.y) / 2;
        counter++;
    }
    center.x = total_x / counter;
    center.y = total_y / counter;

    return center;
}

Point<double> get_centroid_bbox(const std::vector<std::pair<Point<double>, Point<double>>> lines) {
    Point<double> center{0, 0};
    double max_x = 0;
    double min_x = 0;
    double max_y = 0;
    double min_y = 0;

    for (auto line : lines) {
        if (line.first.x > max_x) {
            max_x = line.first.x;
        } else if (line.first.x < min_x) {
            min_x = line.first.x;
        }


        if (line.first.y > max_y) {
            max_y = line.first.y;
        } else if (line.first.y < min_y) {
            min_y = line.first.y;
        }

        if (line.second.x > max_x) {
            max_x = line.second.x;
        } else if (line.second.x < min_x) {
            min_x = line.second.x;
        }

        if (line.second.y > max_y) {
            max_y = line.second.y;
        } else if (line.second.y < min_y) {
            min_y = line.second.y;
        }
    }

    center.x = (max_x + min_x) / 2;
    center.y = (max_y + min_y) / 2;

    return center;
}

template class Point<double>;
template Point<double> get_rotated_direction(Point<double> direction, double angle);
