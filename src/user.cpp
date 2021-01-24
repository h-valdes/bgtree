#include "user.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <toml.hpp>

UserInfo::UserInfo() {
    this->general_info.height = 1080;
    this->general_info.width = 1920;
    this->is_preview = false;
    this->stroke_color = "#FFFFFF";
    this->general_info.background_color = "#546E7A";
    this->general_info.output_file = "background.png";
}

void UserInfo::create_empty_canvas() {
    this->image = std::make_shared<Magick::Image>(
        Magick::Geometry(this->general_info.width, this->general_info.height),
        Magick::Color(this->general_info.background_color));
}

void UserInfo::read_config(std::string config_path) {
    const auto data = toml::parse(config_path);
    if (data.contains("general")) {
        auto general_config = toml::find<config::General>(data, "general");
        this->general_info = general_config;
    }
    
    for (auto drawing_option : this->drawing_options) {
        if (data.contains(drawing_option)) {
            const auto& servers = toml::find(data, drawing_option);
            auto key = drawing_option;
            std::vector<config::Drawable> configs;
            for (const auto& item : servers.as_table()) {
                std::cout << item.first << std::endl;
                auto drawable_config = toml::find<config::Drawable>(servers, item.first);
            } 
        }
    }

}