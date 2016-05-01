#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
using namespace mir;
using namespace sf;
using namespace std;

int main() {
	GameWindow game(VideoMode(200, 200), "Framework");
	while (game.loop());
	return 0;
}