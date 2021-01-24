#include <iostream>
#include <memory>
#include <string>

#include "CLI/CLI.hpp"
#include "fractal_binary_tree.hpp"
#include "fractal_plant.hpp"
#include "user.hpp"

int main(int argc, char** argv) {
    CLI::App app;

    auto user_info = std::make_shared<UserInfo>();

    // Subcommand draw
    auto draw_sub = app.add_subcommand("draw", "Draw");

    // preview flag
    bool flag_preview;
    auto preview_flag = draw_sub->add_flag(
        "--preview, -p", flag_preview, "Display the background with ImageMagick");

    // Path of the output file
    std::string output_path;
    auto output_option = draw_sub->add_option(
        "--output, -o", output_path, "Path to the output file");

    // Path of the config file
    std::string config_path;
    auto config_option = draw_sub->add_option(
        "--config, -c", config_path, "Path to the config file");

    draw_sub->callback([&]() {
        if (*config_option)
            user_info->read_config(config_path);

        if (*preview_flag)
            user_info->is_preview = flag_preview;

        if (*output_option)
            user_info->general_info.output_file = output_path;

        user_info->create_empty_canvas();

        FractalPlant fplant = FractalPlant(user_info);
        fplant.draw();
    });

    CLI11_PARSE(app, argc, argv);

    return EXIT_SUCCESS;
}