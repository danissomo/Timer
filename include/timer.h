#ifndef TIMER
	#include <iostream>
	#include <vector>
	#include <chrono>
	#include <time.h>
	#define TIMER

	//класс-интерфейс Timer виртуальный
	class Timer{
		protected:
			bool started=false;
		
		public:
			virtual void begin()=0;
			virtual double lap()=0;
			virtual double end()=0;
			virtual const double operator[](int index)=0;
	};


	class TimerReal: public Timer{
		protected: 
			std::vector<std::chrono::time_point<std::chrono::steady_clock>> laps;
		public:
			virtual void begin();
			virtual double lap();
			virtual double end();
			virtual const double operator[](int index);
	};


	class TimerClock: public Timer{
		protected:
			std::vector<double> laps;
		public:
			virtual void begin();
			virtual double lap();
			virtual double end();
			virtual const double operator[](int index);
	};
#endif
