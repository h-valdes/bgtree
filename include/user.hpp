#pragma once

#include <Magick++.h>

#include <map>
#include <memory>
#include <string>
#include "config.hpp"

class UserInfo {
   public:
    config::General general_info;
    bool is_preview;
    std::string stroke_color;
    std::shared_ptr<Magick::Image> image;
    std::map<std::string, std::vector<config::LSystem>> drawable_config;
    std::vector<std::string> drawing_options{
        "fractal-plant",
        "fractal-binary-tree"};
    UserInfo();
    void read_config(std::string config_path);
    void create_empty_canvas();
    void draw();
};
