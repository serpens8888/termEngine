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





Hline::Hline(int x1, int x2, int y, int r, int g, int b)
: x1(x1), x2(x2), y(y), r(r), g(g), b(b){

	x1 = wrapX(x1);
	x2 = wrapX(x2);
	y = wrapY(y);
	for(int i = 0;i<x2-x1+1;i++){
		color(x1+i,y,r,g,b);
	}
}

Vline::Vline(int y1, int y2, int x, int r, int g, int b)
: y1(y1), y2(y2), x(x), r(r), g(g), b(b){

	y1 = wrapY(y1);
	y2 = wrapY(y2);
	x = wrapX(x);
	for(int i = 0;i<y2-y1+1;i++){
		color(x,y1+i,r,g,b);
	}
}

rect::rect(int x1, int y1, int x2, int y2, int r, int g, int b)
: x1(x1), y1(y1), x2(x2), y2(y2), r(r), g(g), b(b){

	x1=wrapX(x1);
	y1=wrapY(y1);
	x2=wrapX(x2);
	y2=wrapY(y2);

	for(int i = 0;i<y2-y1+1;i++){
		Hline temp(x1,x2,y1+i,r,g,b);
	}


}


std::vector<int> makeAABB(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY){

	std::vector<int> x(bottomRightX-topLeftX+1);
	std::vector<int> y(bottomRightY-topLeftY+1);
	std::vector<int> final(x.size()*y.size());

	std::ranges::iota(x.begin(),x.end(),topLeftX);
	std::ranges::iota(y.begin(), y.end(), topLeftY);

     	for(int i : y ){
		for(int j : x){
	  		final.push_back(i);
	  		final.push_back(j);
	  	}
	}
	return final;
}

int crossProduct(std::vector<int> vec1, std::vector<int> vec2){
	return (vec1[0]*vec2[1])-(vec1[1]*vec2[0]);
}

tri::tri(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int r, int g, int b)
: Ax(Ax), Ay(Ay),Bx(Bx),By(By), Cx(Cx), Cy(Cy), r(r), g(g), b(g) {


	std::vector<int> triAABB = makeAABB(std::min({Ax, Bx, Cx}),
	 				    std::min({Ay, By, Cy}),
				 	    std::max({Ax, Bx, Cx}),
					    std::max({Ay, By, Cy}));
	
	std::vector<int> AB = {(Bx-Ax), (By-Ay)},
			 BC = {(Cx-Bx), (Cy-By)},
			 CA = {(Ax-Cx), (Ay-Cy)},
			 AP, BP, CP;

	for(int i = 0;i<triAABB.size();i++){
		AP = {(triAABB[i]-Ax), (triAABB[i+1]-Ay)};
		BP = {(triAABB[i]-Bx), (triAABB[i+1]-By)};
		CP = {(triAABB[i]-Cx), (triAABB[i+1]-Cy)};
		int crossA = crossProduct(AP,AB);
		int crossB = crossProduct(BP,BC);
		int crossC = crossProduct(CP,CA);
		if(crossA>=0&&crossB>=0&&crossC>=0){
     			color(triAABB[i], triAABB[i+1],r,g,b);
     		}
		else if(crossA<0&&crossB<0&&crossC<0){
     			color(triAABB[i], triAABB[i+1],r,g,b);
     		}
	}
}



circle::circle(int midpointX, int midpointY, int radius, int r, int g, int b)
: midpointX(midpointX), midpointY(midpointY), radius(radius), r(r), g(g), b(b){

	std::vector<int> circleAABB = makeAABB(midpointX-radius, midpointY-radius, midpointX+radius, midpointY+radius);
	for(int i = 0;i<circleAABB.size();i++){
		if(sqrt((
			(midpointX-circleAABB[i]) * (midpointX-circleAABB[i])) +
			((midpointY-circleAABB[i+1]) * (midpointY-circleAABB[i+1])))<=radius){
				color(circleAABB[i], circleAABB[i+1],r,g,b);
     		}
	}
}














