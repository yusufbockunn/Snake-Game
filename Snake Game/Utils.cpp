#include "Utils.h"


 inline Vector2 Engine::utils::generateRandomPosition(const int xRange,const int yRange)
{
	Vector2 vec2;
	vec2.x = GetRandomValue(0, xRange);
	vec2.y = GetRandomValue(0, yRange);

	return vec2;
}

 inline bool Engine::utils::EventTimer()
{
	double current_time = GetTime();

	double lastUpdateTime = 0;

	//anlık zaman
	//kaç saniye sürcek
	//en son kaydedilen anlık zaman
	
	if (current_time -lastUpdateTime >= specs::interval)
	{
		lastUpdateTime = current_time;
		return true;
	}
	else
	{
		return false;
	}

}

