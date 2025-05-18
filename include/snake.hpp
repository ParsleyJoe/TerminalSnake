#pragma once

enum class direction {
	LEFT, RIGHT, UP, DOWN
};

class Snake
{
private:
	int x = 1;
	int y = 1;
	bool alive = true;
	direction dir = direction::RIGHT;
public:
	void Draw(int gridWidth, int gridHeight);
	void Move(int gridWidth, int gridHeight);
	bool isAlive();
};
