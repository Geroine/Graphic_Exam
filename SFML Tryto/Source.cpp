#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"

using namespace mir;
using namespace sf;
using namespace std;

void main() {
	GameWindow game;
	while (game.loop());
}