#pragma once

#include <Magick++.h>

#include "config.hpp"
#include "geometry.hpp"
#include <memory>

class Spiral {
   protected:
    config::Spiral config;

   public:
    Spiral(config::Spiral config) {
        this->config = config;
    }
    void draw(std::shared_ptr<Magick::Image> image, int image_width, int image_height);
};
