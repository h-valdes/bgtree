#pragma once

#include "lsystem.hpp"

class FractalPlant : public LSystem {
   protected:
    double angle;
   public:
    FractalPlant();
    virtual void draw() override;
};