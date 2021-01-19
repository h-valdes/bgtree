#include <iostream>

#include "CLI/CLI.hpp"
#include "fractal_binary_tree.hpp"
#include "fractal_plant.hpp"

int main(int argc, char** argv) {
    CLI::App app;

    // Subcommand draw
    auto draw_sub = app.add_subcommand("draw", "Draw");
    bool flag_preview;
    draw_sub->add_flag("--preview, -p", flag_preview, "Display the background with ImageMagick");
    draw_sub->callback( [&]() {
        FractalPlant fplant = FractalPlant();
        fplant.draw(flag_preview);
    });


    CLI11_PARSE(app, argc, argv);

    return EXIT_SUCCESS;
}