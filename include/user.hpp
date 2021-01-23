#pragma once

#include <Magick++.h>

#include <string>
#include <memory>

class UserInfo {
   public:
    int width;
    int height;
    bool is_preview;
    std::string background_color;
    std::string stroke_color;
    std::string output_file;
    std::shared_ptr<Magick::Image> image;
    UserInfo();
    void read_config(std::string config_path);
    void create_empty_canvas();
};