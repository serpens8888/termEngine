#include "screen.hpp"

std::vector<std::string> pixels(){
	std::vector<std::string> pixels(rows*cols+1);
	std::fill(pixels.begin(), pixels.end(),"\033[48;2;000;000;000m  ");
	return pixels;
}

int index(int col, int row){
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
		if(i==pixels.size()-1){
			frame.append("\0");
		}
	}
	return frame;
}

void color(int col, int row, std::string r, std::string g, std::string b){
	frame[index(col,row)].replace(7,3,r);
	frame[index(col,row)].replace(11,3,g);
	frame[index(col,row)].replace(15,3,b);
}
