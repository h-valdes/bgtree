#pragma once

#include "lsystem.hpp"

class FractalBinaryTree : public LSystem {
   public:
    FractalBinaryTree();
    virtual void draw() override;
};