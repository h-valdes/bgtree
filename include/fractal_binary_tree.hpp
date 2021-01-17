#pragma once

#include "lsystem.hpp"

class FractalBinaryTree : public LSystem {
   protected:
    virtual std::vector<std::pair<Point, Point>> get_lines() override;

   public:
    FractalBinaryTree();
};