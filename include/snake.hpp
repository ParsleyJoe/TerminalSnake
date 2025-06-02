#pragma once
#include <vector>

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
	int x = 3;
	int y = 1;
	direction dir = direction::RIGHT;
	bool alive = true;
	std::vector<Vector2> snakeBody;
	std::vector<Vector2> changePos; // probably wrong but ey man

public:
	Snake();

	void Draw(int gridWidth, int gridHeight);
	void DrawBody();
	void ChangeDir(char input);
	void Move(int gridWidth, int gridHeight);
	void MoveBody(int gridWidth, int gridHeight);
	bool isAlive();
	// x , y of colliding thing
	bool CheckCollision(int otherX, int otherY);
	void AddBody();
};
