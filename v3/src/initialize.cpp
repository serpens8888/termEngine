#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"
void initialize(){
	frame = pixel();
	std::cout << "\033[?25l";
	drawH(0,25,10,"182", "003","192");
	drawH(0,99,49,"032","192","092");
	std::cout << "\033[0;0H";
	std::cout << render(frame);
}
