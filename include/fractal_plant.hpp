#pragma once

#include "lsystem.hpp"

class FractalPlant : public LSystem {
   protected:
    double angle;
    virtual std::vector<std::pair<cv::Point2d, cv::Point2d>> get_lines() override;

   public:
    FractalPlant();
};