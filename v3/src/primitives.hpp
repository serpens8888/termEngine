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
