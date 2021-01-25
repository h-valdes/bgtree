#pragma once

#include "lsystem/lsystem.hpp"

class Triangle : public LSystem {
   public:
    Triangle(config::LSystem config) : LSystem(config) {
        this->variables = {"F"};
        this->constants = {"+", "-"};
        this->axiom = "F+F+F";
        this->rules.insert({"F", "F-F+F"});
        this->angle = config.angle;
        this->recursions = config.recursions;
        this->length = config.length;
        this->name = "Triangle";
        this->generate_lines();
    }
};