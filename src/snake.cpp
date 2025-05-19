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

	switch (c)
	{
		case 'a':
			dir = direction::LEFT;
			break;
		case 'd':
			dir = direction::RIGHT;
			break;
		case 's':
			dir = direction::DOWN;
			break;
		case 'w':
			dir = direction::UP;
			break;
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
