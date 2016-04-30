#include "window.h"

GameWindow::GameWindow()
	:window(VideoMode(320, 240), "Game window"){

}

GameWindow::GameWindow(VideoMode mode, char * label)
	: window(mode, label) {

}

Processor & GameWindow::processor() {
	return proc;
}

bool GameWindow::loop() {
	globalEvent = Event();
	while (window.pollEvent(globalEvent)) {
		if (globalEvent.type == Event::Closed)
			window.close();
	}
	proc.process();
	return true;
}
