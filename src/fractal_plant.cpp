#include "fractal_plant.hpp"

#include <iostream>
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
    this->generate_lines();
}

void FractalPlant::generate_lines() {
    std::vector<std::pair<Point, Point>> lines;
    auto production = this->produce();

    Point start_point(0, 0);
    Point direction(0, 1);
    double length{4.5};
    std::vector<Point> positions;
    std::vector<Point> directions;

    // Specific for the example 2 of Wikipedia
    Point last_point = start_point;
    Point last_direction = direction;

    Point new_point;
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

    this->lines = lines;
}
