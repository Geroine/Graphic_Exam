#pragma once
#include <list>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
namespace mir {

	struct TimeStamp {
		float tickrate;
		Clock clock;
		TimeStamp() {
			tickrate = 0;
		}
	};

	class Process {
	public:
		virtual bool iterate(const TimeStamp& time) = 0;
	};

	

	class Processor {
		list<Process*> processes;
		int tickrate;
		TimeStamp timeStamp;
		Clock clock;
	public:
		Processor(int tickrate = 800);
		void push(Process& proc);
		bool erase(Process& proc);
		void clear();
		int getSize();
		bool process();
		const TimeStamp& getTimeStamp();
		const Clock& getClock();

		list<Process*>::iterator begin();
		list<Process*>::iterator end();
	};

}