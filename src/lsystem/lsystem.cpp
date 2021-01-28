#include "lsystem/lsystem.hpp"
#include "geometry.hpp"

#include <Magick++.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string LSystem::produce() {
    std::string output = this->axiom;
    // std::cout << "n = " << 0 << " : " << output << std::endl;

    for (int n = 1; n < this->config.recursions + 1; n++) {
        std::string tmp_output = "";
        for (auto cursor_char : output) {
            std::string cursor_str{cursor_char};
            if (std::find(this->constants.begin(), this->constants.end(), cursor_str) != this->constants.end()) {
                tmp_output += cursor_str;
            } else {
                tmp_output += this->rules.at(cursor_str);
            }
        }

        // std::cout << "n = " << n << " : " << tmp_output << std::endl;
        output = tmp_output;
    }

    return output;
}

void LSystem::draw(std::shared_ptr<Magick::Image> image, int image_width, int image_height) {
    // Magick::Image image(Magick::Geometry(width, height), Magick::Color(background_color));
    std::vector<Magick::Drawable> draw_vector;

    image->strokeColor(this->config.stroke_color);
    image->strokeWidth(this->config.stroke_width);

    if (this->config.mirror)
        this->mirror_lines();

    Point<double> center = get_centroid(this->lines);
    std::cout << "Center: " << center.x << " , " << center.y << std::endl;

    int x_offset, y_offset;

    if (this->config.x_centered) {
        x_offset = (image_width / 2) - center.x + this->config.x_offset;
    } else {
        x_offset = config.x_offset;
    }

    if (this->config.y_centered) {
        y_offset = (image_height / 2) - center.y + this->config.y_offset;
    } else {
        y_offset = this->config.y_offset;
    }  

    for (auto line : this->lines) {
        draw_vector.push_back(Magick::DrawableLine(
            line.first.x + x_offset, line.first.y + y_offset,
            line.second.x + x_offset, line.second.y + y_offset));
    }

    for (auto drawable : draw_vector) {
        image->draw(drawable);
    }
}

void LSystem::mirror_lines() {
    std::cout << "Mirror lines" << std::endl;
    std::vector<std::pair<Point<double>, Point<double>>> new_lines;
    for (auto line : this->lines) {
        auto new_first = line.first;
        auto new_second = line.second;
        new_first.x *= -1;
        new_second.x *= -1;
        new_lines.push_back({new_first, new_second});
    }
    this->lines = new_lines;
}

void LSystem::generate_lines() {
    std::vector<std::pair<Point<double>, Point<double>>> lines;
    auto production = this->produce();

    Point<double> start_point(0, 0);
    Point<double> direction(0, 1);
    std::vector<Point<double>> positions;
    std::vector<Point<double>> directions;

    // Specific for the example 2 of Wikipedia
    Point<double> last_point = start_point;
    Point<double> last_direction = direction;

    this->angle_increment = M_PI / 12;

    double length_factor = 1.2;

    Point<double> new_point;
    for (char cursor : production) {
        switch (cursor) {
            case 'X':
                break;
            case '-':
                last_direction = get_rotated_direction<double>(
                    last_direction, -1 * this->config.angle);
                break;
            case '+':
                last_direction = get_rotated_direction<double>(
                    last_direction, this->config.angle);
                break;
            case '|':
                last_direction = get_rotated_direction<double>(
                    last_direction, M_PI);
                break;
            case 'F':
                new_point.x = last_point.x + (last_direction.x * this->config.length);
                new_point.y = last_point.y - (last_direction.y * this->config.length);
                lines.push_back({last_point, new_point});
                last_point = new_point;
                break;
            case 'f':
                new_point.x = last_point.x + (last_direction.x * this->config.length);
                new_point.y = last_point.y - (last_direction.y * this->config.length);
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
            case '#':
                this->config.length += this->config.length_increment;
                break;
            case '!':
                this->config.length -= this->config.length_increment;
                break;
            case '(':
                this->config.angle -= this->config.angle_increment;
                break;
            case ')':
                this->config.angle += this->config.angle_increment;
                break;
            case '>':
                this->config.length *= length_factor;
                break;
            case '<':
                this->config.length /= length_factor;
                break;
        }
    }

    this->lines = lines;
}

void LSystem::set_properties(std::string name) {
    this->rules.clear();

    if (name == "fractal-binary-tree") {
        this->name = "Fractal Binary Tree";
        this->variables = {"X", "F"};
        this->constants = {"[", "]", "-", "+", ">"};
        this->axiom = "FX";
        this->rules.clear();
        this->rules.insert({"X", ">[-FX]+FX"});
        this->rules.insert({"F", "F"});
    } else if (name == "fractal-plant") {
        this->name = "Fractal Plant";
        this->variables = {"X", "F"};
        this->constants = {"+", "-", "[", "]"};
        this->axiom = "X";
        this->rules.clear();
        this->rules.insert({"X", "F+[[X]-X]-F[-FX]+X"});
        this->rules.insert({"F", "FF"});
    } else if (name == "triangle") {
        this->name = "Triangle";
        this->variables = {"F"};
        this->constants = {"+", "-"};
        this->axiom = "F+F+F";
        this->rules.clear();
        this->rules.insert({"F", "F-F+F"});
    } else if (name == "square-sierpinski") {
        this->name = "Square Sierpinski";
        this->variables = {"F", "X"};
        this->constants = {"-", "+"};
        this->axiom = "F+XF+F+XF";
        this->rules.clear();
        this->rules.insert({"X", "XF-F+F-XF+F+XF-F+F-X"});
        this->rules.insert({"F", "F"});
        this->config.angle = M_PI / 2;
    } else if (name == "dragon-curve") {
        this->name = "Dragon Curve";
        this->variables = {"F", "X", "Y"};
        this->constants = {"+", "-"};
        this->axiom = "FX";
        this->rules.insert({"F", "F"});
        this->rules.insert({"X", "X+YF+"});
        this->rules.insert({"Y", "-FX-Y"});
        this->config.angle = M_PI / 2;
    }

    if (this->variables.size() > 0) {
        this->generate_lines();
    }
}
