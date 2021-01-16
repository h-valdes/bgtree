#pragma once

#include <vector>
#include <map>
#include <string>

class LSystem {
   private:
    std::vector<std::string> variables;
    std::string axiom;
    std::map<std::string, std::string> rules;
    void produce();
   public:
    LSystem();
    void draw();
};