#include "object.h"
#include <functional>
using namespace std;
using namespace sf;

void mir::Object::snapToFrame(int w, int h) {
	int height = getTextureSize().y;
	int width = getTextureSize().x;
	for (int i = 0; i < height/h; i++) {
		for (int j = 0; j < width/w; j++) {
			pushFrame(Frame(j*w, i*h, h, w));
		}
	}
}

void mir::Object::pushFrame(const Frame & frame) {
	frames.push(frame);
}

void mir::Object::setFrameIndex(int index) {
	frameIndex = index;
	if (index >= 0 && index < frames.getSize()) {
		_setTextureRect(frames.getFrame(index));
	} else if (index == FullFrame) {
		_setTextureRect(Frame(0, 0, getTextureSize().x, getTextureSize().y));
		frameIndex = FullFrame;
	} else {
		setTextureRect(Frame(0, 0, 0, 0));
		frameIndex = FailedFrame;
	}
}

int mir::Object::getFrameSize() {
	return frames.getSize();
}

int mir::Object::getFrameIndex() {
	return frameIndex;
}

void mir::Object::clearFrames() {
	frames.clear();
}

const mir::FrameContainer& mir::Object::getFrames() {
	return frames;
}

void mir::Object::loadFrames(const FrameContainer & frames) {
	this->frames = frames;
}

Frame mir::Object::getFrame(int index) {
	return frames.getFrame(index);
}

void mir::Object::setFrame(int index, const Frame & frame) {
	frames.setFrame(index, frame);
}

bool mir::Object::isValidFrame() {
	return !(frameIndex == UnknownFrame);
}

Frame mir::Object::getFullFrame() {
	return Frame(0, 0, getTextureSize().x, getTextureSize().y);
}

void mir::Object::setTextureRect(const Frame & frame) {
	Sprite::setTextureRect(frame);
	frameIndex = UnknownFrame;
}

void mir::Object::_setTextureRect(const Frame & frame) {
	Sprite::setTextureRect(frame);
}

void mir::FrameContainer::push(const Frame & frame) {
	frames.push_back(frame);
}

int mir::FrameContainer::getSize() {
	return frames.size();
}

void mir::FrameContainer::clear() {
	frames.clear();
}

void mir::FrameContainer::loadFrames(const FrameContainer & frames) {
	this->frames = frames.frames;
}

Frame mir::FrameContainer::getFrame(int index) {
	Frame result;
	if (index >= frames.size() || index < 0) result = Frame();
	else result = frames[index];
	return result;
}

void mir::FrameContainer::setFrame(int index, const Frame & frame) {
	if (index >= frames.size() || index < 0) return;
	frames[index] = frame;
}

mir::Object::Object() {
	frameIndex = FullFrame;
	solid = false;
	depth = 0;
	group = nullptr;
}

mir::Object::Object(const Object & obj) {
	Sprite::operator=(obj);
	frameIndex = obj.frameIndex;
	frames = obj.frames;
	solid = obj.solid;
	depth = obj.depth;
	group = nullptr;
}

mir::Object::Object(const Sprite & sprite) {
	Sprite::operator=(sprite);
	frameIndex = FullFrame;
	solid = false;
	depth = 0;
	group = nullptr;
}

mir::Object::Object(const Texture & texture) {
	setTexture(texture);
	frameIndex = FullFrame;
	solid = false;
	depth = 0;
	group = nullptr;
}

mir::Object::Object(const Texture & texture, const Frame & rectangle) {
	setTexture(texture);
	setTextureRect(rectangle);
	frameIndex = UnknownFrame;
	solid = false;
	depth = 0;
	group = nullptr;
}

mir::Object & mir::Object::operator=(const Object & obj) {
	if(this == &obj) return *this;
	Sprite::operator=(obj);
	solid = obj.solid;
	depth = obj.depth;
	frameIndex = obj.frameIndex;
	frames = obj.frames;
}

bool mir::Object::isSolid() {
	return solid;
}

void mir::Object::setSolid(bool state) {
	solid = state;
}

int mir::Object::getDepth() {
	return depth;
}

void mir::Object::setDepth(int d) {
	depth = d;
}

void mir::Object::setGroup(ObjectGroup * grp) {
	group = grp;
}

mir::ObjectGroup * mir::Object::getGroup() {
	return group;
}

Sprite mir::Object::getSprite(int index) {
	Sprite spr = *this;
	if (index == CurrentFrame) {
		spr.setTextureRect(getFrame(getFrameIndex()));
		return spr;
	}
	spr.setTextureRect(getFrame(index));
	return spr;
}

Vector2u mir::Object::getTextureSize() {
	Texture txt = *getTexture();
	return txt.getSize();
}

void mir::Object::setSprite(const Sprite & spr) {
	Sprite::operator=(spr);
	frames.clear();
	frameIndex = UnknownFrame;
}
