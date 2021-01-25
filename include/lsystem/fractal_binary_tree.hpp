#pragma once

#include "lsystem/lsystem.hpp"

class FractalBinaryTree : public LSystem {
   public:
    FractalBinaryTree(config::LSystem config) : LSystem(config) {
        // this->variables = {"X", "F"};
        // this->constants = {"[", "]", "-", "+", ">"};
        // this->axiom = "FX";
        // this->rules.insert({"X", ">[-FX]+FX"});
        // this->rules.insert({"F", ""});

        this->variables = {"F"};
        this->constants = {"+", "-"};
        this->axiom = "F+F+F";
        this->rules.insert({"F", "F-F+F"});
        this->angle = M_PI/3;
        this->recursions = 5;
        this->name = "Fractal Binary Tree";
        this->length = 5.5;
        this->generate_lines();
    }
};