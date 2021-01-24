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

void LSystem::draw() {
    int width = this->user_info->general_info.width;
    int height = this->user_info->general_info.height;
    std::string background_color = this->user_info->general_info.background_color;
    std::string stroke_color = this->user_info->stroke_color;
    std::string output_file = this->user_info->general_info.output_file;

    // Magick::Image image(Magick::Geometry(width, height), Magick::Color(background_color));
    std::vector<Magick::Drawable> draw_vector;

    user_info->image->strokeColor(stroke_color);
    user_info->image->strokeWidth(1.3);

    // int x_offset = (width / 2) - this->width;
    int x_offset = (width / 2);
    int y_offset = ((height - this->height) / 2) + this->height;

    for (auto line : this->lines) {
        draw_vector.push_back(Magick::DrawableLine(
            line.first.x + x_offset, line.first.y + y_offset,
            line.second.x + x_offset, line.second.y + y_offset));
    }

    for (auto drawable : draw_vector) {
        user_info->image->draw(drawable);
    }

    if (this->user_info->is_preview == true) {
        user_info->image->display();
    } else {
        user_info->image->write(output_file);
    }
}