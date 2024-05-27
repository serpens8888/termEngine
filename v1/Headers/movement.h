class Point{
private: 
	int x;
	int y;
public:
	Point(int X = 0, int Y = 0) : x(X), y(Y) {} //sets the args to equal the ints
	int getX() const{
		return x;
	}
	int getY() const{
		return y;
	}
	void setX(const int newX){
		x=newX;
	}
	void setY(const int newY){
		y=newY;
	}
};
class Position{
private:
	Point pos;
	Point prev;

public:
	
	Position(Point s,Point n){
		prev.setX(s.getX());
		prev.setY(s.getY());
		s.setX(n.getX());
		s.setY(n.getY());
		pos.setX(s.getX());
		pos.setY(s.getY());

		
	}
	int getPosX() const{
		return pos.getX();
	}
	int getPosY() const{
		return pos.getY();
	}
	void setPosX(const int newX){
		pos.setX(newX);
	}
	void setPosY(const int newY){
		pos.setY(newY);
	}
	int getPrevX(){
		return prev.getX();
	}
	int getPrevY(){
		return prev.getY();
	}
	void setPrev(){
		prev.setX(pos.getX());
		prev.setY(pos.getY());
	}

};

void gotoxy(Position b){
	std::cout << "\033[" << b.getPosY() << ";" << b.getPosX() << "H";

}	

void gotoPrevxy(Position b){
	std::cout << "\033[" << b.getPrevY() << ";" << b.getPrevX() << "H";
}

void WASD(char input, Position &P){
	if(input == 'd'||input == 'D'){
		system("cls");
		P.setPrev();
		P.setPosX(P.getPosX()+1);
		gotoxy(P);
		std::cout << "x";
	}
	else if(input == 's'||input == 'S'){
		system("cls");	
		P.setPrev();
		P.setPosY(P.getPosY()+1);
		gotoxy(P);
		std::cout << "x";
	}
	else if(input == 'a'||input =='A'){
		system("cls");
		P.setPrev();
		P.setPosX(P.getPosX()-1);
		gotoxy(P);
		std::cout << "x";
	}
	else if(input == 'w'||input == 'W'){
		system("cls");
		P.setPrev();	
		P.setPosY(P.getPosY()-1);
		gotoxy(P);
		std::cout << "x";
	}
}
