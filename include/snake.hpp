#pragma once

class Snake
{
private:
	int x = 1;
	int y = 1;
	bool alive = true;
public:
	void Draw(int gridWidth, int gridHeight);
	void Move(int gridWidth, int gridHeight);
	bool isAlive();
};
