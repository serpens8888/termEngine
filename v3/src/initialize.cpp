#include "initialize.hpp"
#include "globals.hpp"
#include "screen.hpp"
#include "primitives.hpp"


void initialize(){
	std::cout << "\033[?25l";
	frame = pixels();
	for(int i = 0;i<10000;i++){
	rect a(i+1,i/2,i+1,i/2,i/5,i/2,i/3);	
	rect b(-i-1,-i/2,-i-1,-i/2,i/3,2*i,i/5);
	rect c(-i,i/2+1,-i,i/2+1,i,i/3,i/2);
	rect d(i,-i/2-1,i,-i/2-1,i/2,3*i,i);
	rect e(i,rows/2+1,i,rows/2+1,i/5,i,i/2);
	rect f(-i,rows/2-1,-i,rows/2-1,i/2,i,i/5);
	rect g(cols/2+1,i/2,cols/2+1,i/2,i/5,2*i,i);
	rect h(cols/2-1,-i/2,cols/2-1,-i/2,i,i/2,2*i);
	std::cout << "\033[0;0H";
	std::cout << render(frame);
	std::this_thread::sleep_for(std::chrono::milliseconds(0));
	}
}
