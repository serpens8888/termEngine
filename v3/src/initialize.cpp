#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"


void initialize(){
	std::cout << "\033[?25l";
	frame = pixels();
	for(int i = 0;i<1000;i+=2){
	Hline line(0,i,i,0+i,0+i,0+i);	
	Vline line2(0,i,i,123+i,123+i,123+i);
	
	std::cout << "\033[0;0H";
	std::cout << render(frame);
	}
}
