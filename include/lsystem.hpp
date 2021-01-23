#pragma once

#include <map>
#include <string>
#include <vector>
#include <geometry.hpp>
#include <user.hpp>
#include <memory>

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
    std::shared_ptr<UserInfo> user_info;
    std::string produce();
    std::vector<std::pair<Point<double>, Point<double>>> lines;
    virtual void generate_lines() = 0;
   public:
    LSystem(std::shared_ptr<UserInfo> user_info) {
        this->user_info = user_info;
    }
    void draw();
};