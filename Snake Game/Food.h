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
		explicit Food();
		void Draw()const override;
		~Food();
		inline Vector2 getPosition()const { return position; }
	};




};
