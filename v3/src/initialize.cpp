#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"


void initialize(){
	std::cout << "\033[?25l";
	frame = pixels();
	for(int i = 0;i<1000;i++){
	Hline line(0,i%(cols),i/2,"223","092","222");	
	Vline line2(0,(i/2)%(rows),i,"015","255","055");
	
	std::cout << "\033[0;0H";
	std::cout << render(frame);
	}
}
