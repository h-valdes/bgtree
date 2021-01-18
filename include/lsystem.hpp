#pragma once

#include <map>
#include <string>
#include <vector>
#include <point.hpp>

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
    std::string produce();
    std::vector<std::pair<Point, Point>> lines;
    virtual void generate_lines() = 0;
   public:
    void draw();
};