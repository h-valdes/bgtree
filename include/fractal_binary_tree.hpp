#pragma once

#include "lsystem.hpp"

class FractalBinaryTree : public LSystem {
   protected:
    virtual std::vector<std::pair<cv::Point2d, cv::Point2d>> get_lines() override;

   public:
    FractalBinaryTree();
};