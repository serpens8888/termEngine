#include "motionControl.hpp"


int pulse(int max, int start,int step, int x){
	std::vector<int> pulsar((max-1)*2);
	for(int i = 0;i<=max-start+1;i++){
		pulsar[i] = start+i*step;
	}
	for(int i = 0;i<((max-1)*2)-max;i++){
		pulsar[max+i] = max-(step+(i*step));
	}
	return pulsar[x%pulsar.size()];
}



int sine(int amplitude, int period, int lr, int ud, int x){
	return (amplitude*(sin((period*x)+lr)))+ud;
}
