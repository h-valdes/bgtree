#include <iostream>

#include "lsystem.hpp"

int main(int argc, char** argv) {
    // Example 1
    // std::vector<std::string> variables = {"A", "B"};
    // std::vector<std::string> constants;
    // std::string axiom = "A";
    // std::map<std::string, std::string> rules;
    // rules.insert({"A", "AB"});
    // rules.insert({"B", "A"});

    // LSystem lsystem1 = LSystem(variables, constants, axiom, rules);
    // lsystem1.draw();

    // Example 1
    std::vector<std::string> variables = {"0", "1"};
    std::vector<std::string> constants = {"[", "]"};
    std::string axiom = "0";
    std::map<std::string, std::string> rules;
    rules.insert({"1", "11"});
    rules.insert({"0", "1[0]0"});

    LSystem lsystem1 = LSystem(variables, constants, axiom, rules);
    lsystem1.draw();


    return EXIT_SUCCESS;
}