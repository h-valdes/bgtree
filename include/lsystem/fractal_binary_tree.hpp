#pragma once

#include "lsystem/lsystem.hpp"

class FractalBinaryTree : public LSystem {
   protected:
    virtual void generate_lines() override;

   public:
    FractalBinaryTree(config::LSystem config);
};