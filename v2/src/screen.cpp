#include "screen.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int arrayIndex(int row, int col){
	int index = ((row*cols)+col);
	return index;
}

void initializeArray(){
	for(int i = 0;i<rows;i++){
		for(int j = 0;j<cols;j++){
			screenData[arrayIndex(i,j)] = pixel;
		}
	}
}

std::wstring renderFrame(){
	std::wstring frame;
	for(int i = 0;i<rows;i++){
		for(int j = 0;j<cols;j++){
			frame.append(screenData[arrayIndex(i,j)]);
		}
		if(i!=rows-1){
			frame.append(L"\n");
		}
		else{
			frame.append(L"\0");
		}
	}
	return frame;
}
void writeFrame(std::wstring frame){
	std::wfilebuf frame1;
	frame1.open("frameBuffer1.txt", std::ios::out | std::ios::trunc);
	std::wostream wos(&frame1);
	wos << frame;
	frame1.close();
}


/*void randomPixel(){ 
	int  TIME = std::time(NULL);
	std::srand(TIME);
	std::wstring a;
	wchar_t one;
	wchar_t two;
	for(int i = 0;i<cols;i++){
		for(int j = 0;j<rows;j++){

			int colorSeed = std::rand()%6+1;
			switch (colorSeed){
				case 1:
				a = L"31";
				break; case 2: 
				a = L"32";
				break;
				case 3:
				a = L"33";
				break;
				case 4:
				a = L"34";
				break;
				case 5:
				a = L"35";
				break;
				case 6:
				a = L"36";
				break;


			}
			one = a.at(0);
			two = a.at(1);
			screenData[arrayIndex(i,j)].at(2) = one; 
			screenData[arrayIndex(i,j)].at(3) = two;
		}
	}
}

*/









