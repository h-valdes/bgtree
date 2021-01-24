#include "fractal_binary_tree.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "geometry.hpp"

FractalBinaryTree::FractalBinaryTree(config::Drawable config) : LSystem(config){
    this->variables = {"0", "1"};
    this->constants = {"[", "]"};
    this->axiom = "0";
    this->rules.insert({"1", "11"});
    this->rules.insert({"0", "1[0]0"});
    this->recursions = 5;
    this->name = "Fractal Binary Tree";
    this->generate_lines();
}

void FractalBinaryTree::generate_lines() {
    std::vector<std::pair<Point<double>, Point<double>>> lines;
    auto production = this->produce();

    Point<double> start_point(0, 0);
    Point<double> direction(0, 1);
    double length{5};
    std::vector<Point<double>> positions;
    std::vector<Point<double>> directions;
    double max_x = 0;
    double min_x = 0;
    double max_y = 0;
    double min_y = 0;

    // Specific for the example 2 of Wikipedia
    Point<double> last_point = start_point;
    Point<double> last_direction = direction;

    Point<double> new_point;
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
                last_direction = get_rotated_direction<double>(last_direction, M_PI / 4);
                break;
            case ']':
                last_direction = get_rotated_direction<double>(directions.back(), -1 * M_PI / 4);
                last_point = positions.back();
                positions.pop_back();
                directions.pop_back();
                break;
        }

        if (new_point.x > max_x) {
            max_x = new_point.x;
        }else if (new_point.x < min_x) {
            min_x = new_point.x;
        }

        if (new_point.y < min_y) {
            min_y = new_point.y;
        } else if (new_point.y > max_y) {
            max_y = new_point.y;
        }
    }

    this->width = static_cast<int>(std::abs(max_x - min_x));
    this->height = static_cast<int>(std::abs(max_y - min_y));
    std::cout << "Width: " << this->width << std::endl;
    std::cout << "Height: " << this->height << std::endl;
    
    this->lines = lines;
}
