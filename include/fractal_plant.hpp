#pragma once

#include "lsystem.hpp"

class FractalPlant : public LSystem {
   protected:
    double angle;
    virtual void generate_lines() override;

   public:
    FractalPlant(config::Drawable config);
};