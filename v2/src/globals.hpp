#pragma once
#include <string>
#define pixel L"\033[37m\u2588\u2588" 
inline int seed = 0;
const int rows = 50;
const int cols = 100;
inline std::wstring screenData[cols*rows];

#define BLK L"30"
#define RED L"31"
#define GRN L"32"
#define YEL L"33"
#define BLU L"34"
#define MAG L"35"
#define CYN L"36"
#define WHT L"37"


#define setColor(row,col,color)  \
				screenData[arrayIndex(row, col)][2] = color[0];	\
				screenData[arrayIndex(row, col)][3] = color[1];
