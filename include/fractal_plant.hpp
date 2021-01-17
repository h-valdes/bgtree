#pragma once

#include "lsystem.hpp"

class FractalPlant : public LSystem {
   protected:
    double angle;
    virtual std::vector<std::pair<Point, Point>> get_lines() override;

   public:
    FractalPlant();
};