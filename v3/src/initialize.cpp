#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"
#include "motionControl.hpp"


void initialize(){
	std::cout << "\033[?25l"; //hide cursor
	for(int i = 0;i<1000;i++){
	frame = pixels(); //initialize the frame string
	circle a(5,5,pulse(5,1,1,i),pulse(255,0,1,i*4),pulse(255,0,1,i*4+123),pulse(255,0,1,i*4+i/2));
	circle b(20,20,pulse(12,1,1,i), 235,235,255);
	circle c(50,25,pulse(23,1,1,i*2),pulse(255,0,1,i),0,40);
	circle d(80,32,pulse(16,1,1,i),0,90,pulse(245,55,1,i));
	circle e(10,40,pulse(10,1,1,i),34,pulse(233,120,1,i),120);
	circle f(90,10,pulse(9,1,1,i),pulse(200,20,1,i),pulse(180,100,1,i),200);
//	rect(30,sine(3,1,0,-1,i), 35,sine(3,1,0,-5,i),i,i,i);
	
	
	std::cout << a.radius;
	std::cout << "\033[0;0H"; //go to top left in terminal
	std::cout << render(frame); // print the frame to the terminal
	std::this_thread::sleep_for(std::chrono::milliseconds(1000/10)); //set the fps
	}
}
