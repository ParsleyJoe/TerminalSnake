#include "snake.hpp"
#include <iostream>
#include <unistd.h>

void Snake::Draw(int gridHeight, int gridWidth)
{
	// 4 and 1 get to first * printed in grid so
	// the first * printed is 0, 0 (origin)
	int row = 4 + y;
	int col = 1 + x;
	std::cout << "\033[" << row << ";" << col << "H" << std::flush;

	std::cout << "#" << std::flush;
}
void Snake::Move(int gridHeight, int gridWidth)
{
	// Input
	char c;
	read(STDIN_FILENO, &c, 1);

	switch (c)
	{
		case 'a':
			dir = direction::LEFT;
		case 'd':
			dir = direction::RIGHT;
		case 's':
			dir = direction::DOWN;
		case 'w':
			dir = direction::UP;
	}

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
	}
}

bool Snake::isAlive()
{
    return alive;
}
