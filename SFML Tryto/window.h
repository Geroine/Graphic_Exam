#pragma once
#include "engine.h"
#include <functional>
#include <list>


using namespace sf;
namespace mir {

	class GameWindow: public Engine {
	public:
		GameWindow();
		GameWindow(VideoMode mode, char* label);
		void iterate();
	};
}