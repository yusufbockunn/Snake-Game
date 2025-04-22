#include "include/Food.h"

using namespace Engine;



Food::Food():position( utils::generateRandomPosition(specs::cellCount,specs::cellCount))
{

	//Image image = LoadImage("Food.png");
	//foodTexture = LoadTextureFromImage(image);
	//UnloadImage(image);
}

void Food::Draw() const 
{
	DrawTexture(foodTexture, position.x * specs::cellSize, position.y * specs::cellSize, WHITE);
	DrawRectangle(position.x * specs::cellSize, position.y * specs::cellSize,specs::cellCount,specs::cellCount, WHITE);
}
Food::~Food()
{

//	UnloadTexture(foodTexture);
}

