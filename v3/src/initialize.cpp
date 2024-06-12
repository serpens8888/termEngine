#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"
#include "motionControl.hpp"


void initialize(){
	std::cout << "\033[?25l"; //hide cursor
	for(int i = 0;i<1000;i++){
	frame = pixels(); //initialize the frame string
	circle a(pulse(100,0,1,i),pulse(50,0,1,i),pulse(20,1,1,i),pulse(255,0,1,i*4),pulse(255,0,1,i*4+123),pulse(255,0,1,i*4+i/2));
	std::cout << a.radius;
	std::cout << "\033[0;0H"; //go to top left in terminal
	std::cout << render(frame); // print the frame to the terminal
	std::this_thread::sleep_for(std::chrono::milliseconds(1000/10)); //set the fps
	}
}
