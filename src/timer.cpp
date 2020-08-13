#include "timer.h"

void TimerClock::begin(){
	if(started){
		#ifdef COUT_CERR
			std::cerr << "begin(): started =true";
		#endif
		return;
	}
	started = true;
	laps.push_back(double(clock()) / double(CLOCKS_PER_SEC)); 
}
 

double TimerClock::end(){
	if(!started){
		#ifdef COUT_CERR
			std::cerr << "end(): started =false";
		#endif
		return 0;
	}
	started = false;
	laps.push_back(double(clock()) / double(CLOCKS_PER_SEC)); 
	return laps.back() - laps[0];
}

//создать один круг, возвращает промежуток между кругами
double TimerClock::lap(){
	if(!started){
		#ifdef COUT_CERR
			std::cerr << "lap(): started =false";
		#endif
		return 0;
	}
	laps.push_back(double(clock()) / double(CLOCKS_PER_SEC));
	return double(laps.back() - laps[laps.capacity() -2])/double(CLOCKS_PER_SEC); 
}


const double TimerClock::operator[](int index){
	
	return  double(laps[index]-laps[0])/double(CLOCKS_PER_SEC); 
}

void TimerReal::begin(){
	if(started){
		#ifdef COUT_CERR
			std::cerr << "begin(): started =true";
		#endif
		return;
	}
	started = true;
	laps.push_back(std::chrono::steady_clock::now()); 
}
 

double TimerReal::end(){
	if(!started){
		#ifdef COUT_CERR
			std::cerr << "end(): started =false";
		#endif
		return 0;
	}
	started = false;
	laps.push_back(std::chrono::steady_clock::now()); 
	auto ret = std::chrono::duration_cast<std::chrono::microseconds>(laps.back() - laps[0]);
	return ret.count() / double(1000);
	
}

//создать один круг, возвращает промежуток между кругами
double TimerReal::lap(){
	if(!started){
		#ifdef COUT_CERR
			std::cerr << "lap(): started =false";
		#endif
		return 0;
	}
	laps.push_back(std::chrono::steady_clock::now());
	
	return std::chrono::duration_cast<std::chrono::seconds>(laps.back() - laps[laps.capacity() -2]).count() / double(1000);
}


const double TimerReal::operator[](int index){
	
	//return  double(laps[index]-laps[0])/double(CLOCKS_PER_SEC); 
	return 0;
}