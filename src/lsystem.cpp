#include "lsystem.hpp"

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

    for (auto line : this->lines) {
        draw_vector.push_back(Magick::DrawableLine(
            line.first.x + x_offset, line.first.y + y_offset,
            line.second.x + x_offset, line.second.y + y_offset));
    }

    for (auto drawable : draw_vector) {
        image->draw(drawable);
    }
}