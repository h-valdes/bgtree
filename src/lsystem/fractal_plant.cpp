#include "lsystem/fractal_plant.hpp"

#include <iostream>
#include "geometry.hpp"

FractalPlant::FractalPlant(config::LSystem config) : LSystem(config) {
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
    std::vector<std::pair<Point<double>, Point<double>>> lines;
    auto production = this->produce();

    Point<double> start_point(0, 0);
    Point<double> direction(0, 1);
    double length{4.5};
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
            case 'X':
                break;
            case '-':
                last_direction = get_rotated_direction(last_direction, -1 * angle);
                break;
            case '+':
                last_direction = get_rotated_direction(last_direction, angle);
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

    if (std::abs(max_x) > std::abs(min_x)) {
        this->width = static_cast<int>(max_x / 2);
    } else {
        this->width = static_cast<int>(min_x / 2);
    }

    // this->width = static_cast<int>(std::abs(max_x - min_x));
    this->height = static_cast<int>(std::abs(max_y - min_y));
    std::cout << "Width: " << this->width << std::endl;
    std::cout << "Height: " << this->height << std::endl;

    this->lines = lines;
}