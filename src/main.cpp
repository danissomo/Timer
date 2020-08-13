#include <iostream>
#include <stdio.h>
#include "timer.h"
#include <vector>
#include <chrono>
#include <unistd.h>


int main(){

	TimerClock h;
	TimerReal realCl;
	realCl.begin();
	h.begin();
	auto j =clock();


	clock_t start, end;
    start = clock();
    int c;
    for (int i = 0; i < 1011; i++) {
        for (int j = 0; j < 300; j++) {
            c++;
        }
    }
    end = clock();
    printf("start = %d, end = %d\n", start, end);
		auto r= h.end();
	auto p = clock();
	auto realEnd = realCl.end();
	
	std::cout<< r<< "\n";
	std::cout << realEnd<< "\n";
	
	
}