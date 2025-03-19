#include "Utils.h"


Vector2 Engine::utils::generateRandomPosition(const int xRange,const int yRange)
{
	Vector2 vec2;
	vec2.x = GetRandomValue(0, xRange);
	vec2.y = GetRandomValue(0, yRange);

	return vec2;
}

bool Engine::utils::EventTimer(double interval)
{
	double current_time = GetTime();

	//anl�k zaman
	//ka� saniye s�rcek
	//en son kaydedilen anl�k zaman

	if (current_time - specs::lastUpdateTime >= interval)
	{
		specs::lastUpdateTime = current_time;
		return true;
	}
	else
	{
		return false;
	}

}

