#include "primitives.hpp"




int wrapX(int x){
	if(x>cols){
		x = x%(cols);
	}
	if(x<0){
		x = (cols)-((-x)%(cols));
	}
return x;
}

int wrapY(int y){
	if(y>rows){
		y = y%(rows);
	}
	if(y<0){
		y = (rows)-(-(y%rows));
	}
return y;
}





Hline::Hline(int x1, int x2, int y, int r, int g, int b){
	x1 = wrapX(x1);
	x2 = wrapX(x2);
	y = wrapY(y);
	for(int i = 0;i<x2-x1+1;i++){
		color(x1+i,y,r,g,b);
	}
}

Vline::Vline(int y1, int y2, int x, int r, int g, int b){
	y1 = wrapY(y1);
	y2 = wrapY(y2);
	x = wrapX(x);
	for(int i = 0;i<y2-y1+1;i++){
		color(x,y1+i,r,g,b);
	}
}
