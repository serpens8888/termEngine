#pragma once
#include "globals.hpp"

std::vector<std::string> pixels();
int index(int col, int row);
std::string render(std::vector<std::string> pixels);
void color(int col, int row, std::string r, std::string g, std::string b);
