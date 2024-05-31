#include "globals.hpp"
#include "screen.hpp"

class Hline{
public:
	int x1;
	int x2;
	int y;
	std::string r;
	std::string g;
	std::string b;
	Hline(int x1, int x2, int y, std::string r, std::string g, std::string b);
};

class Vline{
public:
	int y1;
	int y2;
	int x;
	std::string r;
	std::string g;
	std::string b;
	Vline(int y1, int y2, int x, std::string r, std::string g, std::string b);
};
