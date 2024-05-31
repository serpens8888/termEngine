#include "primitives.hpp"

Hline::Hline(int x1, int x2, int y, std::string r, std::string g, std::string b){
	for(int i = 0;i<x2-x1+1;i++){
		color(x1+i,y,r,g,b);
	}
}
