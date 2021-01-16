#include "lsystem.hpp"

#include <iostream>
#include <algorithm>

std::string LSystem::produce() {
    std::string output = this->axiom;
    std::cout << "n = " << 0 << " : " << output << std::endl;

    for (int n = 1; n < this->recursions + 1; n++) {
        std::string tmp_output = "";
        for (auto cursor_char : output) {
            std::string cursor_str{cursor_char};
            if (std::find(this->constants.begin(), this->constants.end(), cursor_str) != this->constants.end()) {
                tmp_output += cursor_str;
            } else {
                tmp_output += this->rules.at(cursor_str);
            }
        }

        std::cout << "n = " << n << " : " << tmp_output << std::endl;
        output = tmp_output;
    }

    return output;
}