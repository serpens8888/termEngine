#include "screen.hpp"

std::vector<std::string> pixel(){
	std::vector<std::string> pixel(rows*cols+1);
	std::fill(pixel.begin(),pixel.end(),"\033[48;2;000;000;000m  ");
	return pixel;
}

int arrayAccess(int col, int row){
	int x = (row*cols)+col;
	return x;
}

std::string render(std::vector<std::string> pixels){
	std::string frame;
	frame.reserve(pixels.size()+rows);
	for(int i = 0;i<pixels.size()-1;i++){
		frame.append(pixels[i]);
		if(i!=0&&(i+1)%cols==0){
     			frame.append("\n");
     		}
		if(i == pixels.size()-1){
     			frame.append("\0");
     		}
	}
	return frame;
}
