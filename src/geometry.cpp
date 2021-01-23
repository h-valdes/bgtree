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

template class Point<double>;
template Point<double> get_rotated_direction(Point<double> direction, double angle);
