#pragma once

#include <Magick++.h>

#include <map>
#include <memory>
#include <string>
#include <toml.hpp>

struct DrawableConfig {
    std::string stroke_color;
    double stroke_width;
    int x_offset;
    int y_offset;
    bool is_centered;

    void from_toml(const toml::value& v) {
        this->stroke_color = toml::find<std::string>(v, "stroke-color");
        this->stroke_width = toml::find<double>(v, "stroke-width");

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

        if (v.contains("is-centered")) {
            this->is_centered = toml::find<bool>(v, "is-centered");
        } else {
            this->is_centered = true;
        }

        return;
    }
};

class UserInfo {
   public:
    int width;
    int height;
    bool is_preview;
    std::string background_color;
    std::string stroke_color;
    std::string output_file;
    std::shared_ptr<Magick::Image> image;
    std::map<std::string, std::vector<DrawableConfig>> drawable_config;
    std::vector<std::string> drawing_options{
        "fractal-plant",
        "fractal-binary-tree"};
    UserInfo();
    void read_config(std::string config_path);
    void create_empty_canvas();
};
