#include "drawFrame.hpp"
#include <iostream>
#include <vector>
#include "screen.hpp"
#include <algorithm>

void drawHLine(int x1, int x2, int y, std::wstring color){
	std::vector<int> linePixels((x2-x1+1));
	int index = 0;
	for(int i = x1;i<=x2;i++){
	linePixels[index] = i;
	index++;
	}
	for(int i = 0;i<index;i++){
		setColor(y,linePixels[i],color);
	}
}

void drawVLine(int y1, int y2, int x, std::wstring color){
	std::vector<int> linePixels((y2-y1)+1);
	int index = 0;
	for(int i = y1;i<y2;i++){
		linePixels[index] = i;
		index++;
	}
	for(int i = 0;i<index;i++){
		setColor(linePixels[i],x,color);	
	}
}



void drawRect(int x1, int y1, int x2, int y2, std::wstring color){ 
	for(int i = y1;i<=y2;i++){
		drawHLine(x1,x2,i,color);	
	}
}

std::vector<int> triAABB(int Ay, int Ax, int By, int Bx, int Cy, int Cx){
	int topMost = std::min({Ay,By,Cy});
	int bottomMost = std::max({Ay,By,Cy});
	int rightMost = std::max({Ax,Bx,Cx});
	int leftMost = std::min({Ax,Bx,Cx});

	std::vector<int> distX(rightMost-leftMost+1);
	std::vector<int> distY(bottomMost-topMost+1);
	
	for(int i = 0;i<distX.size();i++){
		distX[i] = leftMost+i;			
	}
	for(int i = 0;i<distY.size();i++){
		distY[i] = topMost + i;	
	}
	
	std::vector<int> AABB(distX.size()*distY.size()*2);
	int indexAABB = 0;
	for(int y : distY){
		for(int x : distX){
			AABB[indexAABB] = x;
			AABB[indexAABB+1] = y;
			indexAABB+=2;
		}
	}

	return AABB;
}
int crossProduct(std::vector<int> V1, std::vector<int> V2){
	int x = (V1[0]*V2[1])-(V2[0]*V1[1]);
	return x;

}

void drawTri(int Ay, int Ax, int By, int Bx, int Cy, int Cx,std::wstring color){
	std::vector<int> AABB = triAABB(Ax, Ay, Bx, By, Cx, Cy);
	std::vector<int> AB = {(Bx-Ax),(By-Ay)};
	std::vector<int> BC = {Cx-Bx,Cy-By};
	std::vector<int> CA = {Ax-Cx,Ay-Cy};
	std::vector<int> AP;
	std::vector<int> BP;
	std::vector<int> CP;
	for(int i = 0;i<AABB.size();i++){
		AP = {(AABB[i]-Ax),(AABB[i+1]-Ay)};
		BP = {(AABB[i]-Bx),(AABB[i+1]-By)};
		CP = {(AABB[i]-Cx),(AABB[i+1]-Cy)};
		int cpa = crossProduct(AP,AB);
		int cpb = crossProduct(BP,BC);
		int cpc = crossProduct(CP,CA);
		if(cpa>=0&&cpb>=0&&cpc>=0){
			setColor(AABB[i],AABB[i+1],color);
		}
		else if(cpa<0&&cpb<0&&cpc<0){
			setColor(AABB[i],AABB[i+1],color);

		}
	}
}

std::vector<int> circleAABB(int x, int y, int r){
	int top = y-r;
	int bottom  = y+r;
	int left = x-r;
	int right = x+r;
	std::vector<int> distX(right-left+1);
	std::vector<int> distY(bottom-top+1);
	for(int i = 0;i<distX.size();i++){
		distX[i] = left+i;
	}
	for(int i = 0;i<distY.size();i++){
		distY[i] = top+i;
	}
	std::vector<int> AABB(distX.size()*distY.size()*2);
	int indexAABB = 0;
	for(int y:distY){
		for(int x:distX){
			AABB[indexAABB] = x;
			AABB[indexAABB+1] = y;
			indexAABB+=2;
		}
	}
	return AABB;
}

void drawCircle(int y, int x, int r, std::wstring color){
	std::vector<int> AABB = circleAABB(x,y,r);
	for(int i = 0;i<AABB.size();i+=2){
		int Px = AABB[i];
		int Py = AABB[i+1];
		if(sqrt(((Px-x)*(Px-x))+((Py-y)*(Py-y)))<=r){
			setColor(Px,Py,color)
		}
	}
}

void drawRing(int y, int x, int r, std::wstring color){
	std::vector<int> AABB = circleAABB(x,y,r);
	for(int i = 0;i<AABB.size();i+=2){
		int Px = AABB[i];
		int Py = AABB[i+1];
		if(sqrt(((Px-x)*(Px-x))+((Py-y)*(Py-y)))==r||sqrt(((Px-x)*(Px-x))+((Py-y)*(Py-y)))==r-1){
			setColor(Px,Py,color);
		}
	}
}



















