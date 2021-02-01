#pragma once

#include <Magick++.h>

#include "config.hpp"
#include "geometry.hpp"
#include <memory>
#include <vector>

class Spiral {
   protected:
    config::Spiral config;
    std::vector<std::pair<Point2d, Point2d>> lines;
   public:
    Spiral(config::Spiral config) {
        this->config = config;
    }
    void draw(std::shared_ptr<Magick::Image> image, int image_width, int image_height);
};
