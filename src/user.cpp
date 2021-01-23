#include "user.hpp"

#include <string>
#include <toml.hpp>
#include <iostream>

UserInfo::UserInfo() {
    this->height = 1080;
    this->width = 1920;
    this->is_preview = false;
    this->stroke_color = "#FFFFFF";
    this->background_color = "#546E7A";
    this->output_file = "background.png";
}

void UserInfo::create_empty_canvas() {
    this->image = std::make_shared<Magick::Image>(
        Magick::Geometry(this->width, this->height),
        Magick::Color(this->background_color));
}

void UserInfo::read_config(std::string config_path) {
    const auto data = toml::parse(config_path);
    if (data.contains("general")) {
        const auto& general = toml::find(data, "general");
        if (data.at("general").contains("output"))
            this->output_file = toml::find<std::string>(general, "output-file");
    }

    if (data.contains("draw")) {
        const auto& draw = toml::find(data, "draw");
        if (data.at("draw").contains("background-color"))
            this->background_color = toml::find<std::string>(draw, "background-color");

        if (data.at("draw").contains("stroke-color"))
            this->stroke_color = toml::find<std::string>(draw, "stroke-color");
    }

    if (data.contains("fractal-plant")) {
        const auto& servers = toml::find(data, "fractal-plant");
        for (const auto& item : servers.as_table()) {
            std::cout << item.first << std::endl;
        } 
    }
}