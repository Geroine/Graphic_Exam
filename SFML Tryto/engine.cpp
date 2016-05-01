#include "engine.h"
#include <functional>
using namespace mir;
Engine::Engine()
	:window(VideoMode(320, 240), "Game window"), evl(eventListener) {
}

Engine::Engine(VideoMode mode, char * label)
	: window(mode, label), evl(eventListener){
}

Processor & Engine::processor() {
	return proc;
}

bool Engine::loop() {
	eventProd();
	iterate();
	update();
	return true;
}

void mir::Engine::eventProd(){
	Event event;
	while (window.pollEvent(event)) {
		eventListener.process(event);
	}
}

void mir::Engine::update(){
	window.clear();
	auto iter = todraw.begin();
	while (iter != todraw.end()) {
		window.draw(**iter);
	}
	todraw.clear();
	window.display();
}

void mir::Engine::draw(Drawable & drawable) {
	todraw.push_back(&drawable);
}
