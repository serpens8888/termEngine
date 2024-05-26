#include <string>
#include <vector>
void drawHLine(int x1, int x2, int y, std::wstring color);
void drawVLine(int y1, int y2, int x, std::wstring color);
void drawRect(int x1, int y1, int x2, int y2, std::wstring color);
std::vector<int> triAABB(int Ay, int Ax, int By, int Bx, int Cy, int Cx);
int corssProduct(int V1x,int V1y,int V2x,int V2y);
void drawTri(int Ay, int Ax, int By, int Bx, int Cy, int Cx,std::wstring color);
std::vector<int> circleAABB(int x, int y, int r);
void drawCircle(int y, int x, int r, std::wstring color);
void drawRing(int y, int x, int r, std::wstring color);
