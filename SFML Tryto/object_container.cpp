#include "object_container.h"
using namespace mir;
using namespace std;
using namespace sf;

void ObjectGroup::_clean() {
	if (trashBag.size() == 0) return;
	auto iter = trashBag.begin();
	while (iter != trashBag.end()) {
		auto titer = objects.begin();
		while (titer != objects.end()) {
			if (*iter == *titer) {
				objects.erase(titer);
			}
			titer++;
		}
		iter++;
	}
	trashBag.clear();
}

bool ObjectGroup::checkPt(Object * unit) {
	bool result = (unit != nullptr);
	if (!result) trashBag.push_back(unit);
	return result;
}

void mir::ObjectGroup::toTrashBag(Object * obj) {
	trashBag.push_back(obj);
}

ObjectGroup::ObjectGroup() {
	// Nothing :)
}

void mir::ObjectGroup::push(Object & obj, bool linkGroup) {
	if (linkGroup) obj.setGroup(this);
	objects.push_back(&obj);
}


bool ObjectGroup::erase(Object& unit) {
	_clean();
	auto iter = objects.begin();
	while (iter != objects.end()) {
		if (&unit == *iter) {
			toTrashBag(*iter); //objects.erase(iter);
			return true;
		}
		iter++;
	}
	return false;
}

void ObjectGroup::clear() {
	objects.clear();
	trashBag.clear();
}

list<Object*>::iterator ObjectGroup::begin() {
	_clean();
	return objects.begin();
}

list<Object*>::iterator ObjectGroup::end() {
	_clean();
	return objects.end();
}

void ObjectGroup::iterateAll(int time) {
	_clean();
	auto iter = objects.begin();
	while (iter != objects.end()) {
		if (!checkPt(*iter)) continue;
		(**iter++).iteration(time);
	}
}

void mir::ObjectGroup::drawAll(RenderWindow & screen) {
	vector<int> depthList;
	int curDepth;
	foreach([&depthList](Object& obj) {
		depthList.push_back(obj.getDepth());
	});
	for (int i = 0; i < depthList.size(); i++) {
		curDepth = depthList[i];
		foreach([&curDepth, &screen](Object& obj) {
			if (curDepth == obj.getDepth()) {
				screen.draw(obj);
			}
		});
	}

}


void ObjectGroup::foreach(void_obj_func func) {
	_clean();
	auto iter = begin();
	while (iter != end()) {
		if (!checkPt(*iter)) continue;
		func(**iter);
		iter++;
	}
}

list<Object*> ObjectGroup::find(bool_obj_func func) {
	_clean();
	list<Object*> find_objects;
	auto iter = begin();
	while (iter != end()) {
		if (!checkPt(*iter)) continue;
		if (func(**iter)) find_objects.push_back(*iter);
		iter++;
	}
	return find_objects;
}

bool ObjectGroup::iterate(int time) {
	_clean();
	iterateAll(time);
	return true;
}