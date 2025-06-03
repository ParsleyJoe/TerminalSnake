#pragma once
#include <vector>
#include <deque>

enum class direction {
	LEFT, RIGHT, UP, DOWN
};

struct Vector2
{
	int x;
	int y;
	direction dir;
};

class Snake
{
private:
	direction dir = direction::RIGHT;
	bool alive = true;
	std::deque<Vector2> snakeBody;
	std::vector<Vector2> changePos; // probably wrong but ey man

public:
	Snake();
	void Draw();
	void Input();
	void Move(int gridWidth, int gridHeight);
	bool CheckFoodCollision(int otherX, int otherY);
	void AddBody();
	void BitItself(Vector2& newHead);
	bool isAlive();
};
