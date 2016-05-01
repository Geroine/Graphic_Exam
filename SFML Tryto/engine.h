#pragma once
#include "event_listener.h"
#include "processor.h"
#include "object.h"
#include <list>


using namespace sf;
namespace mir {
	static EventProcessor eventListener;

	class Engine {
	protected:
		Processor proc;
		RenderWindow window;
		list<Drawable*> todraw;
		EventProcessor& evl;
	public:
		Engine();
		Engine(VideoMode mode, char* label);
		Processor& processor();
		bool loop();
		virtual void iterate() = 0;
		virtual void eventProd();
		void update();
		void draw(Drawable& drawable);
	};
}