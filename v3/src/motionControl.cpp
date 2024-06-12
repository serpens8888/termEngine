#include "motionControl.hpp"


int pulse(int max, int start, int x){
	std::vector<int> pulsar((max-1)*2);
	for(int i = 0;i<=max-start+1;i++){
		pulsar[i] = start+i;
	}
	for(int i = 0;i<((max-1)*2)-max;i++){
		pulsar[max+i] = max-(i+1);
	}
	return pulsar[x%pulsar.size()];
}



int sine(int amplitude, int period, int lr, int ud, int x){
	return (amplitude*(sin((period*x)+lr)))+ud;
}
