#pragma once
#include <deque>
#include <raylib.h>
#include <unordered_map>
#include "Specs.h"
#include "Utils.h"
#include "Drawable.h"

using namespace Engine;

class Snake:public Drawable
{
private:
	std::deque<Vector2> body;
	std::unordered_map<Engine::specs::Movement, Vector2> movementSet = { {specs::LEFT,{-1,0}},{specs::RIGHT,{1,0}},{specs::UP,{0,-1}},{specs::DOWN,{0,1}} };
	specs::Movement current_move = specs::LEFT;
	bool isVertical = false;
public:
	explicit Snake(float _height);
	void Draw()const override;
	void Update();
	void handleInput();
	void addBody();
	Vector2 getHead()const;
	std::deque<Vector2> getBody()const;
	~Snake();
};

