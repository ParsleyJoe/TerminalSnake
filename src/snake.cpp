#include "snake.hpp"
#include <iostream>

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
	if (x < gridWidth) 
	{
		++x;
	}
}

bool Snake::isAlive()
{
    return alive;
}
