#pragma once

#include "lsystem.hpp"

class FractalBinaryTree : public LSystem {
   protected:
    virtual std::string produce() override;
   public:
    FractalBinaryTree();
    virtual void draw() override;
};