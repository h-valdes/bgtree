#pragma once

#include <geometry.hpp>
#include <map>
#include <memory>
#include <string>
#include <user.hpp>
#include <vector>

#include "config.hpp"

class LSystem {
   protected:
    std::vector<std::string> variables;
    std::vector<std::string> constants;
    std::string axiom;
    std::map<std::string, std::string> rules;
    int recursions;
    std::string name;
    double angle_increment;
    double length_increment;
    config::LSystem config;
    std::string produce();
    std::vector<std::pair<Point<double>, Point<double>>> lines;
    void generate_lines();

   public:
    LSystem(config::LSystem config) {
        this->config = config;
    }
    void draw(std::shared_ptr<Magick::Image> image, int image_width, int image_height);
    void mirror_lines();
    void set_properties(std::string name);
};