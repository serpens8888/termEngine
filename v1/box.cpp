#include <iostream>


int main(){
	int x;
	int y;
	std::cout << "x" << std::endl;
	std::cin >> x;
	std::cout << "y" << std::endl;
	std::cin >> y;
	for(int i = 0;i<x;i++){
		std::cout << "__";
	} std::cout << "\n";
	for(int i = 1;i<y;++i){
		for(int i = 0;i<2*x;i++){
			if(i==0){
				std::cout << "|";
			}
			else if(i==2*x-1){
				std::cout << "|";
			}
			else{
				std::cout << " ";
			}
		}	std::cout << "\n";
	}

	for(int i = 0;i<x;i++){
		if(i==0){
			std::cout << "|_";
		} else if(i==x-1){
			std::cout << "_|";
		} else
		std::cout << "__";
	} std::cout << "\n";
	return 0;
}
