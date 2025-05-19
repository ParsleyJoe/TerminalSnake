#pragma once

class Food
{
private:
	int x;
	int y;
public:
	// Generate position in constructor
	Food(int gridWidth, int gridHeight);
	void Draw();

};
