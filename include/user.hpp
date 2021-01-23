#pragma once

#include <string>

class UserInfo {
   public:
    int width;
    int height;
    bool is_preview;
    std::string background_color;
    std::string stroke_color;
    std::string output_file;

    UserInfo() {
        this->height = 1080;
        this->width = 1920;
        this->is_preview = false;
        this->stroke_color = "#FFFFFF";
        this->background_color = "#546E7A";
        this->output_file = "background.png";
    }
};