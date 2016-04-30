#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "object_container.h"
#include "window.h"
using namespace mir;
using namespace sf;
using namespace std;

Event event;

int main() {
	GameWindow game;
	while (game.loop());

	return 0;
}