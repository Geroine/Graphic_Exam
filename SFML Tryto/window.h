#pragma once
#include "processor.h"
using namespace sf;
static Event globalEvent;
class GameWindow {
	Processor proc;
	RenderWindow window;
public:
	GameWindow();
	GameWindow(VideoMode mode, char* label);
	Processor& processor();
	bool loop();
};