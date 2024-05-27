#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
void initialize(){
	std::vector<std::string> frame = pixel();
	std::cout << "\033[?25l";
	for(int i = 0;i<frame.size();i++){
	std::cout << "\033[0;0H";
	colorDirect(i,"255","255","255");
	std::cout << render(frame);
	}
}
