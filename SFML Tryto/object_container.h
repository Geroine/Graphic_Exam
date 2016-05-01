#pragma once
#include "object.h"
#include <list>
#include <functional>

using namespace sf;

namespace mir {
	typedef function<void(Object&)> void_obj_func;
	typedef function<bool(Object&)> bool_obj_func;

	class ObjectGroup : public Process{
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

		void iterateAll(const TimeStamp& time);
		void drawAll(Engine& window);
		// Алгоритмы для группы
		void foreach(void_obj_func func);
		list<Object*> find(bool_obj_func func);

		bool iterate(const TimeStamp& time);
	};
}