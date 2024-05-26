#include <C:/c++/TermEngine/Headers/movement.h>
#include <C:/c++/TermEngine/Headers/level.h>
char Initialize(){
	system("cls");
	Point start(10,10);
	Point next(20,20);
	Position CharPos(start, next);

	while(true){
		char input = _getch();
		char close = 27;	
		if(input == close){ 
			system("cls");
			std::cout << "are you sure you would like to quit? (y/n)" << std::endl;
			char q;
			std::cin >> q;
			rerun:
			if(q == 'y'||q == 'Y')
				exit(0);
			else if (q == 'n'||q == 'N'){
				system("cls");
				continue;
			}	
			
			else if (q != 'y' && q != 'Y' && q != 'n' && q != 'N'){

				std::cout << "not y/n, re-enter" << std::endl;
				std::cin >> q;
				goto rerun;
			}
		}
		WASD(input, CharPos);
		level lev;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		continue;
	}
}

