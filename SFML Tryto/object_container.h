#pragma once
#include <SFML/Graphics.hpp>
#include "object.h"
#include <list>
#include <functional>



namespace mir {
	typedef function<void(Object&)> void_obj_func;
	typedef function<bool(Object&)> bool_obj_func;

	class ObjectGroup {
		list<Object*> objects;
		list<Object*> trashBag;
	protected:
		void _clean();
		bool checkPt(Object* unit);
		void toTrashBag(Object* obj);

	public:
		ObjectGroup();
		void push(Object& obj, bool linkGroup = true);
		bool erase(Object& unit);
		void clear();

		// Итераторы
		list<Object*>::iterator begin();
		list<Object*>::iterator end();

		void iterateAll(int time);
		void drawAll(RenderWindow& screen);
		// Алгоритмы для группы
		void foreach(void_obj_func func);
		list<Object*> find(bool_obj_func func);

		bool iterate(int time);
	};
}