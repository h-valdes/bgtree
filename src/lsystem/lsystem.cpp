#include "lsystem/lsystem.hpp"

#include <Magick++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::string LSystem::produce() {
    std::string output = this->axiom;
    std::cout << "n = " << 0 << " : " << output << std::endl;

    for (int n = 1; n < this->recursions + 1; n++) {
        std::string tmp_output = "";
        for (auto cursor_char : output) {
            std::string cursor_str{cursor_char};
            if (std::find(this->constants.begin(), this->constants.end(), cursor_str) != this->constants.end()) {
                tmp_output += cursor_str;
            } else {
                tmp_output += this->rules.at(cursor_str);
            }
        }

        std::cout << "n = " << n << " : " << tmp_output << std::endl;
        output = tmp_output;
    }

    return output;
}

void LSystem::draw(std::shared_ptr<Magick::Image> image, int width, int height) {

    // Magick::Image image(Magick::Geometry(width, height), Magick::Color(background_color));
    std::vector<Magick::Drawable> draw_vector;

    image->strokeColor(config.stroke_color);
    image->strokeWidth(config.stroke_width);

    int x_offset, y_offset;

    if (config.x_centered) {
        x_offset = (width / 2) + config.x_offset;
    } else {
        x_offset = config.x_offset;
    }

    if (config.y_centered) {
        y_offset = ((height - this->height) / 2) + this->height + config.y_offset;
    } else {
        y_offset = config.y_offset;
    }

    if (config.mirror)
        this->mirror_lines();

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
    double length{4.5};
    std::vector<Point<double>> positions;
    std::vector<Point<double>> directions;
    double max_x = 0;
    double min_x = 0;
    double max_y = 0;
    double min_y = 0;

    double angle = M_PI / 8;

    // Specific for the example 2 of Wikipedia
    Point<double> last_point = start_point;
    Point<double> last_direction = direction;

    double width_increment = 0.3;
    double angle_increment = M_PI/12;

    Point<double> new_point;
    for (char cursor : production) {
        switch (cursor) {
            case 'X':
                break;
            case '-':
                last_direction = get_rotated_direction<double>(last_direction, -1 * angle);
                break;
            case '+':
                last_direction = get_rotated_direction<double>(last_direction, angle);
                break;
            case '|':
                last_direction = get_rotated_direction<double>(last_direction, M_PI);
                break;
            case 'F':
                new_point.x = last_point.x + (last_direction.x * length);
                new_point.y = last_point.y - (last_direction.y * length);
                lines.push_back({last_point, new_point});
                last_point = new_point;
                break;
            case 'f':
                new_point.x = last_point.x + (last_direction.x * length);
                new_point.y = last_point.y - (last_direction.y * length);
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
                length += width_increment;
                break;
            case '!':
                length -= width_increment;
                break;
            case '(':
                angle -= angle_increment;
                break;
            case ')':
                angle += angle_increment;
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