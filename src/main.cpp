#include <iostream>
#include <memory>
#include <string>
#include <toml.hpp>

#include "CLI/CLI.hpp"
#include "fractal_binary_tree.hpp"
#include "fractal_plant.hpp"
#include "user.hpp"

int main(int argc, char** argv) {
    CLI::App app;

    auto user_info = std::make_shared<UserInfo>();

    app.set_config("--config");

    // Subcommand draw
    auto draw_sub = app.add_subcommand("draw", "Draw");

    // preview flag
    bool flag_preview;
    auto preview_flag = draw_sub->add_flag(
        "--preview, -p", flag_preview, "Display the background with ImageMagick");

    // background color option
    std::string background_color;
    auto background_option = draw_sub->add_option(
        "--background, -b", background_color, "Hexadecimal background color");

    // stroke color option
    std::string stroke_color;
    auto stroke_option = draw_sub->add_option(
        "--stroke, -s", stroke_color, "Hexadecimal stroke color");

    draw_sub->callback([&]() {
        if (*preview_flag)
            user_info->is_preview = flag_preview;

        if (*background_option)
            user_info->background_color = background_color;

        if (*stroke_option)
            user_info->stroke_color = stroke_color;

        FractalPlant fplant = FractalPlant(user_info);
        fplant.draw();
    });

    CLI11_PARSE(app, argc, argv);

    return EXIT_SUCCESS;
}