#include "globals.hpp"
#include "screen.hpp"



int wrapX(int x);

int wrapY(int y);



class Hline{
public:
	int x1;
	int x2;
	int y;
	int r;
	int g;
	int b;
	Hline(int x1, int x2, int y, int r, int g, int b);
};

class Vline{
public:
	int y1;
	int y2;
	int x;
	int r;
	int g;
	int b;
	Vline(int y1, int y2, int x, int r, int g, int b);
};

class rect{
	public:
		int x1;
		int y1;
		int x2;
		int y2;
		int r;
		int g;
		int b;
		rect(int x1, int y1, int x2, int y2, int r, int g, int b);
};

std::vector<int> makeAABB(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
int crossProduct(std::vector<int> vec1, std::vector<int> vec2);

class tri{
	public:
		int Ax;
		int Ay;
		int Bx;
		int By;
		int Cx;
		int Cy;
		int r;
		int g;
		int b;
		tri(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int r, int g, int b);

};

class circle{
public:
	int midpointX;
	int midpointY;
	int radius;
	int r;
	int g;
	int b;
	circle(int midpointX, int midpointY, int radius, int r, int g, int b);
};

class character{
public:
	int originX;
	int originY;
	character(int originX,int originY);
};








