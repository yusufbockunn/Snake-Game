#include "include/Snake.h"

using namespace Engine;

Snake::Snake(float _height)
{
	body = { {9, _height}, {8, _height}, {7, _height} };
	current_move = specs::RIGHT;
	isVertical = false;
}

void Snake::Draw() const
{
	for (const auto& segment : body)
	{
		Rectangle rect = { segment.x * specs::cellSize, segment.y * specs::cellSize, specs::cellSize, specs::cellSize };
		DrawRectangleRounded(rect, 0.5f, 8, specs::darkGreen);
	}
}

void Snake::Update()
{
	if (utils::EventTimer())
	{
		Vector2 moveVec = Engine::specs::movementSet.at(current_move);
		Vector2 head = body.front();

		Vector2 newHead = {
			fmodf(head.x + moveVec.x + specs::cellCount, specs::cellCount),
			fmodf(head.y + moveVec.y + specs::cellCount, specs::cellCount)
		};

		body.pop_back();
		body.push_front(newHead);

		isVertical = (moveVec.y != 0);
	}
}

//void Snake::handleInput()
//{
//	if (IsKeyPressed(KEY_W) && !isVertical)
//		setDirection(specs::UP);
//	else if (IsKeyPressed(KEY_S) && !isVertical)
//		setDirection(specs::DOWN);
//	else if (IsKeyPressed(KEY_D) && isVertical)
//		setDirection(specs::RIGHT);
//	else if (IsKeyPressed(KEY_A) && isVertical)
//		setDirection(specs::LEFT);
//}

void Snake::setDirection(specs::Movement dir)
{
	// Ters yöne dönmeyi engelle
	if ((dir == specs::UP && current_move == specs::DOWN) ||
		(dir == specs::DOWN && current_move == specs::UP) ||
		(dir == specs::LEFT && current_move == specs::RIGHT) ||
		(dir == specs::RIGHT && current_move == specs::LEFT))
	{
		return;
	}
	current_move = dir;
}

specs::Movement Snake::getDirection() const
{
	return current_move;
}

void Snake::addBody()
{
	// Yeni parça, son parçanýn arkasýna ekleniyor
	Vector2 tail = body.back();
	Vector2 beforeTail = body[body.size() - 2];
	Vector2 diff = { tail.x - beforeTail.x, tail.y - beforeTail.y };

	body.push_back({ tail.x + diff.x, tail.y + diff.y });
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
