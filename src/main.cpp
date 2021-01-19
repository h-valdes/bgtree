#include <iostream>

#include "fractal_binary_tree.hpp"
#include "fractal_plant.hpp"
#include "CLI/CLI.hpp"

int main(int argc, char** argv) {
    CLI::App app;

    FractalPlant fplant = FractalPlant();
    fplant.draw();

    CLI11_PARSE(app, argc, argv);

    return EXIT_SUCCESS;
}