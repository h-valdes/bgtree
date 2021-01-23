#include "user.hpp"
#include <toml.hpp>

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
    if (data.contains("draw")) {
        const auto& draw = toml::find(data, "draw");
        if (data.at("draw").contains("preview"))
            this->is_preview = toml::find<bool>(draw, "preview");
    }
}