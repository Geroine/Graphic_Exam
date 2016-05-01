#include "unit.h"
//#include "animation.h"
#include <iostream>
using namespace mir;

mir::Unit::Unit() {
	loadFromFile("img/rpg_char.bmp",Color::White);
	snapToFrame(16, 16);
	setFrame(4, Frame(16 * 4, 0, -16, 16));
	setScale(4, 4);
	setPosition(100, 100);

}

bool mir::Unit::iterate(const TimeStamp & time) {
	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
		timer.start();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num2)) {
		timer.pause();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num3)) {
		timer.reload();
	}
	std::cout << timer.getTime() << endl;

	return true;
}