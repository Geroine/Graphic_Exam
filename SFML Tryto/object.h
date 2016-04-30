#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

typedef Rect<int> Frame;

namespace mir {
	class FrameContainer {
		vector<Frame> frames;
	public:
		void push(const Frame& frame);
		int getSize();
		void clear();
		void loadFrames(const FrameContainer& frames);
		Frame getFrame(int index);
		void setFrame(int index, const Frame& frame);
	};
	class ObjectGroup;
	class Object: public Sprite{
	protected:
		FrameContainer frames;
		int frameIndex;
		bool solid;
		int depth;
		ObjectGroup* group;

	public:
		enum {
			FullFrame = -1,
			UnknownFrame = -2,
			FailedFrame = -3,
			CurrentFrame = -4
		};
		void test() {
			
		}
		Object();
		Object(const Object& object);
		Object(const Sprite& sprite);
		Object(const Texture& texture);
		Object(const Texture& texture, const Frame& rectangle);

		Object& operator=(const Object& obj);

		bool isSolid();
		void setSolid(bool state);

		int getDepth();
		void setDepth(int d);

		void setGroup(ObjectGroup* grp);
		ObjectGroup* getGroup();

		Sprite getSprite(int index = CurrentFrame);

		Vector2u getTextureSize();

		void setSprite(const Sprite& spr);

		/* Методы для работы с фреймами спрайта */
		void snapToFrame(int w, int h);
		void pushFrame(const Frame& frame);
		void setFrameIndex(int index);
		int getFrameSize();
		int getFrameIndex();
		void clearFrames();
		const FrameContainer& getFrames();
		void loadFrames(const FrameContainer& frames);
		Frame getFrame(int index);
		void setFrame(int index, const Frame& frame);
		bool isValidFrame();
		Frame getFullFrame();

		/* Переопределенные методы */
		void setTextureRect(const Frame& frame);

		virtual bool iteration(int time) { return false; };

	protected:
		void _setTextureRect(const Frame& frame);
	};
}
