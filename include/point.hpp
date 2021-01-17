#pragma once

class Point {
   public:
    double x;
    double y;
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Point(int x, int y) {
        this->x = static_cast<double>(x);
        this->y = static_cast<double>(y);
    }
};