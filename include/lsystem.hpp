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
    std::string produce();
    virtual std::vector<std::pair<Point, Point>> get_lines() = 0;

   public:
    void draw();
};