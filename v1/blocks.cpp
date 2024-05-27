#include <iostream>
#include <locale>
#include <thread>
#include <chrono>

class Position{
	public:
		int x;
		int y;
		Position(int x= 0, int y = 0):x(x), y(y){

		}
		int Changex(int a){
			x = x + a;
			return x;
		}
		int Changey(int a){
			y = y+a;
			return y;
		}
};


void Gotoxy(int x, int y){
	std::cout << "\033[" << y << ";" << x << "H";
}


int main(){
	std::locale::global(std::locale(""));
	wchar_t block = L'█';
	int b;
	std::cout << "Jump height: " << std::endl;
	std::cin >> b;
	int posx;
	std::cout << "right shift: " << std::endl;
	std::cin >> posx;
	int posy;
	std::cout << "down shift: " << std::endl;
	std::cin >> posy;
	Position Block(posx,posy);
	Gotoxy(Block.x, Block.y);
	for(int i = 0;i<b;i++){
		std::cout << "\033[32m" << "___";
	}

	
	for(int i = 0;i<b;i++){
		if(i==0){
			std::wcout << block;
		}
		else if(i<(b/2)){
			Block.Changex(1);
			Block.Changey(-1);
			Gotoxy(Block.x, Block.y);
			std::wcout << "\033[37m" << block;
		}
		else if(i==b/2){
			Block.Changex(1);
			Gotoxy(Block.x, Block.y);
			std::wcout << "\033[37m" << block;
		}
		else if(i>b/2){
			Block.Changex(1);
			Block.Changey(1);
			Gotoxy(Block.x, Block.y);
		
			std::wcout << "\033[37m" << block;
		}

			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			system("cls");
			Gotoxy(posx,posy);
			for(int i = 0;i<b;i++){
				std::cout << "\033[32m" << "__";
			}

	}
return 0;	
}
