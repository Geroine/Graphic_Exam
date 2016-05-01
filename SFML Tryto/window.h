#pragma once
#include "engine.h"
#include <functional>
#include <list>
#include "unit.h"

using namespace sf;
namespace mir {

	class GameWindow: public Engine {
		Unit unit;
		Object bckg;
	public:
		GameWindow();
		GameWindow(VideoMode mode, char* label);
		void iterate();
	};
}