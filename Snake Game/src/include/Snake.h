#pragma once
#include <deque>
#include <raylib.h>
#include <unordered_map>
#include "Specs.h"
#include "Utils.h"
#include "Drawable.h"

namespace Engine
{
	class Snake : public Drawable
	{
	private:
		std::deque<Vector2> body;


		specs::Movement current_move = specs::RIGHT;
		bool isVertical = false;

	public:
		explicit Snake(float _height);

		void Draw() const override;
		void Update();
		void addBody();

		Vector2 getHead() const;
		std::deque<Vector2> getBody() const;

		void handleInput();                  // Sadece kullanýcý girdisi için
		void setDirection(specs::Movement); // RL ajan için
		specs::Movement getDirection() const;

		~Snake();
	};
}
