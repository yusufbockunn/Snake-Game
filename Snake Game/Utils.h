#pragma once
#include "Specs.h"
#include <raylib.h>
namespace Engine
{
	namespace utils
	{
		Vector2 generateRandomPosition(const int xRange, const int yRange);
		bool EventTimer(double interval);

	};

};

