#pragma once

#include "snake.hpp"
class Food
{
private:
	int x;
	int y;
public:

	// public for deleting in vector<food> foods
	bool eaten = false;
	Food(Vector2& vec);
	void Draw();
	int GetX();
	int GetY();
	void Ate();
};
