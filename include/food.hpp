#pragma once

class Food
{
private:
	int x;
	int y;
	bool eaten = false;
public:
	// Generate position in constructor
	Food(int gridWidth, int gridHeight);
	void Draw();
	int GetX();
	int GetY();
	void Ate();
};
