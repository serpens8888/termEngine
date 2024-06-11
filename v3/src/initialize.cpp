#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"


void initialize(){
	std::cout << "\033[?25l"; //hide cursor
	for(int i = 0;i<1000;i++){
	frame = pixels(); //initialize the frame string
	circle a(i,i,15,255,255,255);
	std::cout << a.radius;
	std::cout << "\033[0;0H"; //go to top left in terminal
	std::cout << render(frame); // print the frame to the terminal
	std::this_thread::sleep_for(std::chrono::milliseconds(1000/30)); //set the fps
	}
}
