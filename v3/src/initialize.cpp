#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"


void initialize(){
	std::cout << "\033[?25l";
	frame = pixels();
	Hline line(3,82,30,"023","182","092");	
	std::cout << "\033[0;0H";
	std::cout << render(frame);

}
