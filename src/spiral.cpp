#include "spiral.hpp"

void Spiral::draw(
    std::shared_ptr<Magick::Image> image, int image_width, int image_height) {
    std::vector<Magick::Drawable> draw_vector;

    image->strokeColor(this->config.stroke_color);
    image->strokeWidth(this->config.stroke_width);

    if (this->config.mirror)
        this->lines = mirror_lines(this->lines);   

    for (auto drawable : draw_vector)
        image->draw(drawable);

}