#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



static int cols = 100;
static int rows = 50;

#define color(col,row,r,g,b)    frame[arrayAccess(col,row)].replace(7,3,r);\
				frame[arrayAccess(col,row)].replace(11,3,g);\
				frame[arrayAccess(col,row)].replace(15,3,b);
#define colorDirect(pos,r,g,b) frame[pos].replace(7,3,r);\
			  frame[pos].replace(11,3,g);\
			  frame[pos].replace(15,3,b);

inline std::vector<std::string> frame;
