#pragma once

#include "lsystem/lsystem.hpp"

class FractalPlant : public LSystem {
   public:
    FractalPlant(config::LSystem config) : LSystem(config) {
        this->variables = {"X", "F"};
        this->constants = {"+", "-", "[", "]"};
        this->axiom = "X";
        this->rules.insert({"X", "F+[[X]-X]-F[-FX]+X"});
        this->rules.insert({"F", "FF"});
        this->recursions = 6;
        this->angle = M_PI / 8;
        this->length = 4.5;
        this->name = "Fractal Plant";
        this->generate_lines();
    }
};