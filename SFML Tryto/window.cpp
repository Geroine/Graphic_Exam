#include "window.h"
#include <functional>
#include <list>
#include "unit.h"
#include "engine.h"

using namespace mir;
GameWindow::GameWindow()
	:Engine(VideoMode(320, 240), "Game window"){
	evl.push([this](Event& event) {
		if (event.type == sf::Event::Closed)
			window.close();
	});

	processor().push(unit);

	bckg.loadFromFile("img/bckg.bmp");
}

GameWindow::GameWindow(VideoMode mode, char * label)
	: Engine(mode, label) {
	evl.push([this](Event& event){
		if (event.type == sf::Event::Closed)
			window.close();
	});
}

void mir::GameWindow::iterate() {
	bckg.setPosition(50, 50);
	proc.process();
	draw(bckg);
	draw(unit);
}
