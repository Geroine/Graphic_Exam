#pragma once
#include <list>
#include <SFML/Graphics.hpp>
using namespace std;

class Process {
public:
	virtual bool iterate(int time) = 0;
};

class Processor {
	list<Process*> processes;
	int tickrate;
	sf::Clock clock;
	int time = 0;
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
