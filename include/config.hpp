#pragma once

#include <cmath>
#include <string>
#include <toml.hpp>

namespace config {
struct LSystem {
    std::string stroke_color;
    double stroke_width;
    int x_offset;
    int y_offset;
    int recursions;
    double angle;
    double angle_increment;
    double length;
    double length_increment;
    bool x_centered;
    bool y_centered;
    bool mirror;

    void from_toml(const toml::value& v) {
        this->stroke_color = toml::find<std::string>(v, "stroke-color");
        this->stroke_width = toml::find<double>(v, "stroke-width");

        if (v.contains("recursions")) {
            this->recursions = toml::find<int>(v, "recursions");
        } else {
            this->recursions = 2;
        }

        if (v.contains("length")) {
            this->length = toml::find<double>(v, "length");
        } else {
            this->length = 2;
        }

        if (v.contains("length-increment")) {
            this->length_increment = toml::find<double>(v, "length-increment");
        } else {
            this->length_increment = this->length / 10;
        }

        if (v.contains("angle")) {
            this->angle = toml::find<double>(v, "angle");
        } else {
            this->angle = M_PI / 4;
        }

        if (v.contains("angle-increment")) {
            this->angle_increment = toml::find<double>(v, "angle-increment");
        } else {
            this->angle_increment = this->angle / 10;
        }

        if (v.contains("x-offset")) {
            this->x_offset = toml::find<int>(v, "x-offset");
        } else {
            this->x_offset = 0;
        }

        if (v.contains("y-offset")) {
            this->y_offset = toml::find<int>(v, "y-offset");
        } else {
            this->y_offset = 0;
        }

        if (v.contains("x-centered")) {
            this->x_centered = toml::find<bool>(v, "x-centered");
        } else {
            this->x_centered = true;
        }

        if (v.contains("y-centered")) {
            this->y_centered = toml::find<bool>(v, "y-centered");
        } else {
            this->y_centered = true;
        }

        if (v.contains("mirror")) {
            this->mirror = toml::find<bool>(v, "mirror");
        } else {
            this->mirror = false;
        }

        return;
    }
};

struct General {
    std::string output_file;
    std::string background_color;
    int width;
    int height;

    void from_toml(const toml::value& v) {
        if (v.contains("output-file")) {
            this->output_file = toml::find<std::string>(v, "output-file");
        } else {
            this->output_file = "background.png";
        }

        if (v.contains("background-color")) {
            this->background_color = toml::find<std::string>(v, "background-color");
        } else {
            this->background_color = false;
        }

        if (v.contains("width")) {
            this->width = toml::find<int>(v, "width");
        } else {
            this->width = 1920;
        }

        if (v.contains("height")) {
            this->height = toml::find<int>(v, "height");
        } else {
            this->height = 1080;
        }
    }
};

};  // namespace config