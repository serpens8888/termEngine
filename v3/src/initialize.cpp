#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"
#include "motionControl.hpp"
#include "movement.hpp"


void initialize(){
	std::cout << "\033[?25l"; //hide cursor
	int startPos[2] = {0,24};
	
	int ieye = 1;

	frame = pixels(); //initialize the frame string
	while(2){
	//background
	frame = pixels(); //initialize the frame string
	rect(0,30,99,49,10,55,10);	
	rect(0,0,99,29,50,20,65);
	rect(0,35,99,49,100,50,25);


	//tree
	rect(25,24,29,30, 180,90,45);
	tri(21,24,27,9,32,24,20,80,30);
	rect(75,26,80,32, 190,95,42);
	tri(68,26,77,11,87,25,25,75,23);

	//stars
	circle(5,5,pulse(2,1,ieye), 230,220,200);
	circle(30,8,pulse(3,1,ieye), 230,210,240);
	circle(90,9,pulse(2,1,ieye+1), 255,220,200);
	circle(65,4,pulse(2,1,ieye), 220,240,190);

	
	//character	
	std::vector<int> a = WASD(startPos[0],startPos[1]);
	startPos[0] = a[0]; startPos[1] = a[1];
	rect(a[0],a[1],a[0]+3,a[1]+6,255,255,255);
	rect(a[0]+2,a[1]+2,a[0]+3,a[1]+2,0,0,0);
	

	std::cout << "\033[0;0H"; //go to top left in terminal
	std::cout << render(frame); // print the frame to the terminal
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000/60)); //set the fps
	ieye += 1;
	}
}
