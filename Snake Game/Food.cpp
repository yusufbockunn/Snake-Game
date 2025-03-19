#include "Food.h"

using namespace Engine;



Food::Food(int cellCount):position( utils::generateRandomPosition(0,cellCount))
{

	Image image = LoadImage("Graphics/Boost.png");
	foodTexture = LoadTextureFromImage(image);
	UnloadImage(image);
}

void Food::Draw() const 
{
	DrawTexture(foodTexture, position.x * specs::cellSize, position.y * specs::cellSize, WHITE);
}
Food::~Food()
{

	UnloadTexture(foodTexture);
}

Vector2 Food::getPosition()
{
	return position;
}