#include "screen.hpp"
#include <iostream>
void renderLoop(){
	initializeArray();
	system("cls");
	while(true){
		writeFrame(renderFrame());
		system("powershell.exe Get-Content frameBuffer1.txt");
		std::cout << "\033[0;0H";
	}
}
	
