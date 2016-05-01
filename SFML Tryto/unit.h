#pragma once
#include "object.h"
#include "processor.h"
#include "animation.h"
namespace mir {
	class Unit : public Object , public Process {
	public:
		Timer timer;
		Unit();
		bool iterate(const TimeStamp& time);
	};
}