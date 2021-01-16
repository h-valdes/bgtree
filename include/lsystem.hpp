#pragma once

#include <map>
#include <string>
#include <vector>

class LSystem {
   protected:
    std::vector<std::string> variables;
    std::vector<std::string> constants;
    std::string axiom;
    std::map<std::string, std::string> rules;
    int recursions;
    virtual std::string produce() = 0;
   public:
    virtual void draw() = 0;
};