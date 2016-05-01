#include "window.h"
#include <functional>
#include <list>

#include "unit.h"

using namespace mir;
GameWindow::GameWindow()
	:Engine(VideoMode(320, 240), "Game window"){

}

GameWindow::GameWindow(VideoMode mode, char * label)
	: Engine(mode, label) {
	evl.push([this](Event& event){
		if (event.type == sf::Event::Closed)
			window.close();
	});
	evl.push([this](Event& event) {
		if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::A)
			window.setPosition(Vector2i(20, 20));
	});
}

void mir::GameWindow::iterate() {
	proc.process();
}
