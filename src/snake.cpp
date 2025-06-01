#include "snake.hpp"
#include <iostream>
#include <unistd.h>

Snake::Snake()
{
	// start with 3 total segments (head included)
	AddBody();
	AddBody();
}

void Snake::Draw(int gridWidth, int gridHeight)
{
	// 4 and 1 get to first * printed in grid so
	// the first * printed is 0, 0 (origin)
	int row = 4 + y;
	int col = 1 + x;
	std::cout << "\033[" << row << ";" << col << "H" << std::flush;

	std::cout << "#" << std::flush;
	DrawBody();
}

void Snake::DrawBody()
{
	for (int i = 0; i < snakeBody.size(); ++i)
	{
		std::cout << "\033[H" << std::flush;
		int row = 4 + snakeBody[i].y;
		int col = 1 + snakeBody[i].x;
		std::cout << "\033[" << row << ";" << col << "H" << std::flush;
		std::cout << "#" << std::flush;
	}
}

void Snake::Move(int gridHeight, int gridWidth)
{
	// "Limit Movement"
	if ( x > gridWidth || y > gridHeight)
	{
		if ( x > gridWidth)
			x = 1;
		if ( y > gridHeight)
			y = 1;
		return;
	}
	if (x < 1 || y < 1)
	{	
		if ( x < 1)
			x = gridWidth;
		if ( y < 1)
			y = gridHeight;
		return;
	}

	// Input
	char c;
	read(STDIN_FILENO, &c, 1);

	// input to change direction
	switch (c)
	{
		case 'a':
			dir = direction::LEFT;
			changePos = {x, y, dir};
			break;
		case 'd':
			dir = direction::RIGHT;
			changePos = {x, y, dir};
			break;
		case 's':
			dir = direction::DOWN;
			changePos = {x, y, dir};
			break;
		case 'w':
			dir = direction::UP;
			changePos = {x, y, dir};
			break;
	}

	// Moves according to direction
	switch (dir) 
	{
		case direction::UP:
			y--;
			break;
		case direction::DOWN:
			y++;
			break;
		case direction::LEFT:
			x--;
			break;
		case direction::RIGHT:
			x++;
			break;
		default:
			std::cout << "ERROR direction isn't a valid enum" << std::flush;
			break;
	}
	MoveBody(gridWidth, gridHeight);
}

void Snake::MoveBody(int gridWidth, int gridHeight)
{
	for (Vector2& vec : snakeBody)
	{

		if (vec.x == changePos.x && vec.y == changePos.y && vec.dir != dir)
		{
			vec.dir = dir;
		}

		switch(vec.dir)
		{
			case direction::DOWN:
				++vec.y;
				break;
			case direction::UP:
				--vec.y;
				break;
			case direction::LEFT:
				--vec.x;
				break;
			case direction::RIGHT:
				++vec.x;
				break;
		}
	}
}


bool Snake::isAlive()
{
    return alive;
}

bool Snake::CheckCollision(int otherX, int otherY)
{
	if ( x == otherX && y == otherY)
	{
		AddBody();
		return true;
	}
	return false;
}

void Snake::AddBody()
{
	Vector2 end = Vector2 {x, y, dir};
	if (!snakeBody.empty())
		end = snakeBody.back();

	switch(end.dir)
	{
		case direction::DOWN:
			snakeBody.push_back(Vector2{end.x, end.y - 1, end.dir});
			break;
		case direction::UP:
			snakeBody.push_back(Vector2{end.x, end.y + 1, end.dir});
			break;
		case direction::LEFT:
			snakeBody.push_back(Vector2{end.x + 1, end.y, end.dir});
			break;
		case direction::RIGHT:
			snakeBody.push_back(Vector2{end.x - 1, end.y, end.dir});
			break;
	}
}
