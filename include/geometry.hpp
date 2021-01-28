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

typedef Point<double> Point2d;

class Line {
   public:
    Point2d start;
    Point2d end;
    Line(Point2d start, Point2d end) {
        this->start = start;
        this->end = end;
    }
};

double get_length(Point2d v);

double dot_product(Point2d v1, Point2d v2);

double cross_product(Point2d v1, Point2d v2);

double get_angle(Point2d v1, Point2d v2);

Point2d get_rotated_direction(Point2d direction, double angle);

Point2d get_centroid(std::vector<std::pair<Point2d, Point2d>> lines);

Point2d get_centroid_bbox(std::vector<std::pair<Point2d, Point2d>> lines);

Point2d convert_to_point(Point2d point);