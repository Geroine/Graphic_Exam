#include <vector>
#include <SFML/System.hpp>
#include "animation.h"

using namespace mir;

mir::Animation::Animation() {
	speed = 1;
	state = ANIM_STOP;
	around = false;
}

mir::Animation::Animation(const Animation & obj) {
	frames = obj.frames;
	speed = obj.speed;
	timer = obj.timer;
	state = obj.state;
	around = false;
}

void mir::Animation::setSpeed(int speed) {
	if (speed < 0) speed = 0;
	this->speed = speed;
}

int mir::Animation::getSpeed() {
	return speed;
}

bool mir::Animation::isEnd() {
	return false;
}

bool mir::Animation::isPlay() {
	return false;
}

bool mir::Animation::isStop() {
	return false;
}

void mir::Animation::start() {
	timer.start();
}

void mir::Animation::pause() {
	timer.pause();
}

void mir::Animation::reload() {
	timer.reload();
}

int mir::Animation::frame() {
	return speed;
}

void mir::Animation::push(int num) {
	frames.push_back(num);
}

void mir::Animation::push(int * start, int count) {
	for (int i = 0; i < count; i++) {
		frames.push_back(*(start + i));
	}
}

void mir::Animation::erase(int id) {
	if (id < 0 && id >= frames.size()) return;
	auto iter = frames.begin()+id;
	frames.erase(iter);
}

void mir::Animation::clear() {
	frames.clear();
}

int mir::Animation::getSize() {
	return frames.size();
}

unsigned mir::Timer::getMs() {
	return clock.getElapsedTime().asMilliseconds();
}

mir::Timer::Timer() {
	tickrate = 0;
	tickrateStart = 0;
	tickratePause = 0;
	state = ANIM_STOP;
}

void mir::Timer::start() {
	update();
	state = ANIM_PLAY;
	tickrateStart = getMs();
	tickrate = tickratePause;
}

void mir::Timer::pause() {
	update();
	tickratePause = tickrate;
	state = ANIM_STOP;
}

void mir::Timer::reload() {
	tickratePause = 0;
	tickrate = 0;
	tickrateStart = getMs();
}

void mir::Timer::update() {
	if (state == ANIM_PLAY){
			tickrate = (getMs() - tickrateStart + tickratePause);
	}
}

unsigned mir::Timer::getTime() {
	update();
	return tickrate;
}
