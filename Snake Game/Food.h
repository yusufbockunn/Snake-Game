#pragma once
#include <raylib.h>
#include "Drawable.h"
#include "Utils.h"

namespace Engine
{

	class Food:public Drawable
	{
	private:
		Vector2 position;
		Texture2D foodTexture;

	public:
		explicit Food(int cellCount);
		void Draw()const override;
		~Food();
		inline Vector2 getPosition();
	};

	/*class Food
	{
	private:
		Vector2* position;
		Texture2D foodTexture;

		Vector2* GenerateRandomPos(int cellCount)
		{
			float x = GetRandomValue(0, cellCount - 1);
			float y = GetRandomValue(0, cellCount - 1);
			return new Vector2{ x,y };

		}

	public:
		Food(int cellCount) :position(GenerateRandomPos(cellCount))
		{
			Image image = LoadImage("Graphics/Boost.png");
			foodTexture = LoadTextureFromImage(image);
			UnloadImage(image);
		}


		void Draw(float cellSize)
		{
			DrawTexture(foodTexture, position->x * cellSize, position->y * cellSize, WHITE);
		}
		~Food()
		{
			delete[] position;

			UnloadTexture(foodTexture);
		}

		Vector2 getPosition()
		{
			return *position;
		}

	};*/


};
