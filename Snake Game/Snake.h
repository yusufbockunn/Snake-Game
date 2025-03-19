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
	//Color darkGreen = { 43,51,24,255 };
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

//class Snake
//{
//private:
//	std::deque<Vector2> body;
//	std::unordered_map<Engine::specs::Movement, Vector2> movementSet = { {specs::LEFT,{-1,0}},{specs::RIGHT,{1,0}},{specs::UP,{0,-1}},{specs::DOWN,{0,1}} };
//	Color darkGreen = { 43,51,24,255 };
//	specs::Movement current_move = specs::LEFT;
//	bool isVertical = false;
//public:
//	Snake(float _height)
//	{
//     	body=	{ Vector2{ 9,_height }, Vector2{ 8,_height }, Vector2{ 7,_height }};
//	}
//	void Draw(float cellSize)
//	{
//		for (int i = 0; i < body.size(); i++)
//		{
//			Rectangle snakeRec = Rectangle{ body[i].x * cellSize , body[i].y * cellSize, cellSize, cellSize };
//			DrawRectangleRounded(snakeRec, 0.5, 8, darkGreen);
//		}
//	}
//
//	void Update()
//	{
//
//		if(utils::EventTimer())
//		{
//		
//			body.pop_back();
//			body.push_front(Vector2{ static_cast<float>(static_cast<int>(body[0].x + movementSet.find(current_move)->second.x + cellCount) % cellCount),  static_cast<float>(static_cast<int>(body[0].y + movementSet.find(current_move)->second.y + cellCount) % cellCount)});
//			isVertical = (movementSet.find(current_move)->second.y == 0 ? false : true);
//		
//		}
//
//		handleInput();
//
//
//	}
//
//	void handleInput()
//	{
//
//			if (IsKeyPressed(KEY_W) && !isVertical)
//			{
//				current_move = specs::UP;
//
//			}
//
//			else if (IsKeyPressed(KEY_S) && !isVertical )
//			{
//				current_move = specs::DOWN;
//
//
//			}
//
//
//
//			else if (IsKeyPressed(KEY_D)&& isVertical)
//			{
//				current_move = specs::RIGHT;
//				isVertical = false;
//			}
//
//			else if (IsKeyPressed(KEY_A)&& isVertical)
//			{
//				current_move = specs::LEFT;
//
//				isVertical = false;
//
//
//			}
//
//	}
//
//	//bool EventTrigger(double interval)
//	//{
//	//	double current_time = GetTime();
//
//	//	//anlýk zaman
//	//	//kaç saniye sürcek
//	//	//en son kaydedilen anlýk zaman
//
//	//	if (current_time - specs::lastUpdateTime >= interval)
//	//	{
//	//		specs::lastUpdateTime = current_time;
//	//		return true;
//	//	}
//	//	else
//	//	{
//	//		return false;
//	//	}
//	//}
//
//	void addBody()
//	{
//
//		if(isVertical)
//		{
//			body.push_back(Vector2{ body.back().x,body.back().y-1});
//		}
//		else
//		{
//			body.push_back(Vector2{ body.back().x,body.back().y - 1 });
//
//		}
//	
//	
//	}
//
//	Vector2 getHead() const
//	{
//		return body.front();
//	}
//
//	std::deque<Vector2> getBody() const
//	{
//		return body;
//	}
//
//	~Snake()
//	{
//		body.clear();
//		
//	}
//
//
//};

