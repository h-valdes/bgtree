#pragma once

#include "lsystem.hpp"

class FractalBinaryTree : public LSystem {
   protected:
    virtual void generate_lines() override;

   public:
    FractalBinaryTree(config::Drawable config);
};