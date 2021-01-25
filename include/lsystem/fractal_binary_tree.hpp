#pragma once

#include "lsystem/lsystem.hpp"

class FractalBinaryTree : public LSystem {
   public:
    FractalBinaryTree(config::LSystem config) : LSystem(config) {
        this->variables = {"X", "F"};
        this->constants = {"[", "]", "-", "+", ">"};
        this->axiom = "FX";
        this->rules.insert({"X", ">[-FX]+FX"});
        this->rules.insert({"F", ""});

        this->angle = config.angle;
        this->recursions = config.recursions;
        this->length = config.length;
        this->name = "Fractal Binary Tree";
        this->generate_lines();
    }
};