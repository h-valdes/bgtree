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
        this->recursions = config.recursions;
        this->angle = config.angle;
        this->length = config.length;
        this->name = "Fractal Plant";
        this->generate_lines();
    }
};