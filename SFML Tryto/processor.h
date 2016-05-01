#pragma once
#include <list>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
namespace mir {

	struct TimeStamp {
		int tickrate;
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
		TimeStamp time;
	public:
		Processor(int tickrate = 800);
		void push(Process& proc);
		bool erase(Process& proc);
		void clear();
		int getSize();
		bool process();

		list<Process*>::iterator begin();
		list<Process*>::iterator end();
	};

}