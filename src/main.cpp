#include <iostream>
#include <memory>
#include <string>

#include "user.hpp"

int main(int argc, char** argv) {
    std::string config_path;

    if (argc >= 2) {
        config_path = argv[1];
    } else {
        return EXIT_FAILURE;
    }

    std::cout << config_path << std::endl;

    auto user_info = std::make_shared<UserInfo>();
    user_info->is_preview = true;

    user_info->read_config(config_path);

    user_info->draw();

    return EXIT_SUCCESS;
}