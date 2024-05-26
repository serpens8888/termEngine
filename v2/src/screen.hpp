#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "globals.hpp"
#include <string>


int arrayIndex(int row, int col);
void initializeArray();
std::wstring renderFrame();
void writeFrame(std::wstring frame);
void randomPixel();


#endif



