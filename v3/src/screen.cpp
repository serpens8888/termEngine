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

std::string colorPad(std::string color){
	if(color.length()==1){
		color.insert(0,"00");
	}
	else if(color.length()==2){
		color.insert(0,"0");
	}
	return color;
}

void color(int col, int row, int r, int g, int b){
	if(col>cols-1){
		col = col%(cols-1);
	}
	if(row>rows-1){
		row = row%(rows-1);
	}
	if(r>255) { r = r%255; }
	if(g>255) { g = g%255; }
	if(b>255) { b = b%255; }
	if(r<0) { r = 255-((-r)%255); }
	if(g<0) { g = 255-((-r)%255); }
	if(b<0) { b = 255-((-r)%255); }
	std::string a = std::to_string(r);
	std::string c = std::to_string(g);
	std::string d = std::to_string(b);
	a = colorPad(a);
	c = colorPad(c);
	d = colorPad(d);

	frame[index(col,row)].replace(7,3,a);
	frame[index(col,row)].replace(11,3,c);
	frame[index(col,row)].replace(15,3,d);
}
