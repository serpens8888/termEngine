#pragma once
#include "globals.hpp"

std::vector<std::string> pixels();
int index(int col, int row);
std::string render(std::vector<std::string> pixels);
void color(int col, int row, int r, int g, int b);
std::string colorPad(std::string color);
