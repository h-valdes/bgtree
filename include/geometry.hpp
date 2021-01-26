#pragma once

#include <cmath>
#include <vector>

template <class T>
class Point {
   public:
    T x;
    T y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

template <class T>
class Line {
   public:
    Point<T> start;
    Point<T> end;
    Line(Point<T> start, Point<T> end) {
        this->start = start;
        this->end = end;
    }
};

template <class T>
double get_length(Point<T> v);

template <class T>
double dot_product(Point<T> v1, Point<T> v2);

template<class T>
double cross_product(Point<T> v1, Point<T> v2);

template<class T>
double get_angle(Point<T> v1, Point<T> v2);

template<class T>
Point<T> get_rotated_direction(Point<T> direction, T angle);

template<class T>
Point<double> get_center(std::vector<std::pair<Point<T>, Point<T>>> lines);

template<class T>
Point<T> convert_to_point(Point<T> point);