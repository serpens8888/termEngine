#include "initialize.hpp"
#include "screen.hpp"
#include <locale>
#include <iostream>
#include <thread>
#include <chrono>
#include "drawFrame.hpp"
void initialize(){
	std::locale::global(std::locale(""));
	initializeArray();
	system("cls");
	int a = 60;
	while(true){
	initializeArray();
	drawRect(30,0,99,49,CYN);
	drawRect(0,0,10,49,GRN);
	drawCircle(25,25,5,MAG);
	drawCircle (10,40,3,BLK);
	drawTri(10,10,15,3,60,40,YEL);
	drawTri(60,2,75,45,92,5,BLU);
	drawRing(25,25,10,RED);
	drawCircle(a,25,10,BLK);
	a++;
	writeFrame(renderFrame());
	system("powershell.exe Get-Content frameBuffer1.txt");
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::wcout << L"\033[0;0H";
	}

	
}
