#include "Snake.h"

using namespace Engine;

Snake::Snake(float _height)
{
	body = { Vector2{ 9,_height }, Vector2{ 8,_height }, Vector2{ 7,_height } };
}
void Snake::Draw() const
{
	for (int i = 0; i < body.size(); i++)
	{
		Rectangle snakeRec = Rectangle{ body[i].x * specs::cellSize , body[i].y * specs::cellSize, specs::cellSize, specs::cellSize };
		DrawRectangleRounded(snakeRec, 0.5, 8, specs::darkGreen);
	}
}

void Snake::Update()
{

	if (utils::EventTimer())
	{

		body.pop_back();
		body.push_front(Vector2{ static_cast<float>(static_cast<int>(body[0].x + movementSet.find(current_move)->second.x + specs::cellCount) % specs::cellCount),  static_cast<float>(static_cast<int>(body[0].y + movementSet.find(current_move)->second.y + specs::cellCount) % specs::cellCount) });
		isVertical = (movementSet.find(current_move)->second.y == 0 ? false : true);

	}

	handleInput();


}

void Snake::handleInput()
{

	if (IsKeyPressed(KEY_W) && !isVertical)
	{
		current_move = specs::UP;

	}

	else if (IsKeyPressed(KEY_S) && !isVertical)
	{
		current_move = specs::DOWN;


	}



	else if (IsKeyPressed(KEY_D) && isVertical)
	{
		current_move = specs::RIGHT;
		isVertical = false;
	}

	else if (IsKeyPressed(KEY_A) && isVertical)
	{
		current_move = specs::LEFT;

		isVertical = false;


	}

}

//bool EventTrigger(double interval)
//{
//	double current_time = GetTime();

//	//anlýk zaman
//	//kaç saniye sürcek
//	//en son kaydedilen anlýk zaman

//	if (current_time - specs::lastUpdateTime >= interval)
//	{
//		specs::lastUpdateTime = current_time;
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

void Snake::addBody()
{

	if (isVertical)
	{
		body.push_back(Vector2{ body.back().x,body.back().y - 1 });
	}
	else
	{
		body.push_back(Vector2{ body.back().x,body.back().y - 1 });

	}


}

Vector2 Snake::getHead() const
{
	return body.front();
}

std::deque<Vector2> Snake::getBody() const
{
	return body;
}

Snake::~Snake()
{
	body.clear();

}
