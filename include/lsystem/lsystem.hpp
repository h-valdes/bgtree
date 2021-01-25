#pragma once

#include <map>
#include <string>
#include <vector>
#include <geometry.hpp>
#include <user.hpp>
#include <memory>
#include "config.hpp"

class LSystem {
   protected:
    std::vector<std::string> variables;
    std::vector<std::string> constants;
    std::string axiom;
    std::map<std::string, std::string> rules;
    int recursions;
    std::string name;
    int width;
    int height;
    config::LSystem config;
    std::string produce();
    std::vector<std::pair<Point<double>, Point<double>>> lines;
    void generate_lines();
   public:
    LSystem(config::LSystem config) {
        this->config = config;
    }
    void draw(std::shared_ptr<Magick::Image> image, int width, int height);
    void mirror_lines();
};