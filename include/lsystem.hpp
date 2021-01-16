#pragma once

#include <map>
#include <string>
#include <vector>

class LSystem {
   private:
    std::vector<std::string> variables;
    std::vector<std::string> constants;
    std::string axiom;
    std::map<std::string, std::string> rules;
    int recursions;
    std::string produce();
   public:
    LSystem(
        std::vector<std::string> variables,
        std::vector<std::string> constants,
        std::string axiom,
        std::map<std::string, std::string> rules,
        int recursions);
    void draw();
};