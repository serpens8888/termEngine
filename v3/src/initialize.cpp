#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"
#include "motionControl.hpp"


void initialize(){
	std::cout << "\033[?25l"; //hide cursor
	frame = pixels(); //initialize the frame string
	for(int i = 0;i<10000;i++){
	circle(i, sine(21,2,0,0,i)+24,4,pulse(255,0,i+84),pulse(255,0,i+168),pulse(255,0,i));
	std::cout << "\033[0;0H"; //go to top left in terminal
	std::cout << render(frame); // print the frame to the terminal
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000/60)); //set the fps
	}
}
