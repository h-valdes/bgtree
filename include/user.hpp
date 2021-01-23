#pragma once

class UserInfo {
   public:
    int width;
    int height;
    bool is_preview;
    UserInfo() {
        this->height = 1080;
        this->width = 1920;
        this->is_preview = false;
    }
    void set_dimensions(int width, int height) {
        this->width = width;
        this->height = height;
    }
};