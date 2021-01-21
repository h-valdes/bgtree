#pragma once

#include "lsystem.hpp"

class FractalBinaryTree : public LSystem {
   protected:
    virtual void generate_lines() override;

   public:
    FractalBinaryTree(std::shared_ptr<user_info_t> user_info);
};