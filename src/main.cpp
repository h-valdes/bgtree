#include <iostream>

#include "lsystem.hpp"

int main(int argc, char** argv) {
    std::vector<std::string> variables = {"0", "1"};
    std::vector<std::string> constants = {"[", "]"};
    std::string axiom = "0";
    std::map<std::string, std::string> rules;
    rules.insert({"1", "11"});
    rules.insert({"0", "1[0]0"});

    LSystem lsystem = LSystem(variables, constants, axiom, rules, 4);
    lsystem.draw();


    return EXIT_SUCCESS;
}