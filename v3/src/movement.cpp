#include "movement.hpp"
#include "globals.hpp"
#include "primitives.hpp"


std::vector<int> WASD(int startX, int startY){
	while(1){
	std::string input;
	std::getline(std::cin, input);
	if(input=="w"||input=="W"){
		startY-=1;
	}
	if(input=="a"||input=="A"){
		startX-=1;
	}	
	if(input=="s"||input=="S"){
		startY+=1;
	}
	if(input=="d"||input=="D"){
		startX+=1;
	}
	input.clear();	

	std::vector<int> pos = { startX,startY };
	return pos;

	}
}
