#include "primitives.hpp"

Hline::Hline(int x1, int x2, int y, std::string r, std::string g, std::string b){
	if(x1<0){ x1=(cols-1)-(-(x1%(cols-1))); }
	if(x1>cols-1){ x1=x1%(cols-1); }
	if(x2<0){ x2 = (cols-1)-(-(x2%cols-1)); }
	if(x2>cols-1){ x2=x2%(cols-1); }
	if(y<0){ y=(rows-1)-(-(y%rows-1)); }
	if(y>rows-1){ y=y%(rows-1); }
for(int i = 0;i<x2-x1+1;i++){
		color(x1+i,y,r,g,b);
	}
}

Vline::Vline(int y1, int y2, int x, std::string r, std::string g, std::string b){
	if(y1<0){ y1=(rows-1)-(-(y1%(rows-1))); }
	if(y1>rows-1){ y1=y1%(rows-1); }
	if(y2<0){ y2 = (rows-1)-(-(y2%rows-1)); }
	if(y2>rows-1){ y2=y2%(rows-1); }
	if(x<0){ x=(cols-1)-(-(x%cols-1)); }
	if(x>cols-1){ x=x%(cols-1); }
for(int i = 0;i<y2-y1+1;i++){
		color(x,y1+i,r,g,b);
	}
}
