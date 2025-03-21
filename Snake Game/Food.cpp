#include "Food.h"

using namespace Engine;



Food::Food():position( utils::generateRandomPosition(specs::cellCount,specs::cellCount))
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

