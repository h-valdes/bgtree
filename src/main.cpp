#include <iostream>

#include "CLI/CLI.hpp"
#include "fractal_binary_tree.hpp"
#include "fractal_plant.hpp"
#include "user.hpp"
#include <memory>

int main(int argc, char** argv) {
    CLI::App app;

    auto user_info = std::make_shared<UserInfo>();

    // Subcommand draw
    auto draw_sub = app.add_subcommand("draw", "Draw");
    bool flag_preview;
    draw_sub->add_flag("--preview, -p", flag_preview, "Display the background with ImageMagick");
    draw_sub->callback( [&]() {
        user_info->is_preview = flag_preview;
        FractalPlant fplant = FractalPlant(user_info);
        fplant.draw();
    });

    CLI11_PARSE(app, argc, argv);

    return EXIT_SUCCESS;
}