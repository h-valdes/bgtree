#pragma once

#include <map>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <string>
#include <vector>

class LSystem {
   protected:
    std::vector<std::string> variables;
    std::vector<std::string> constants;
    std::string axiom;
    std::map<std::string, std::string> rules;
    int recursions;
    std::string name;
    std::string produce();
    virtual std::vector<std::pair<cv::Point2d, cv::Point2d>> get_lines() = 0;

   public:
    void draw();
};