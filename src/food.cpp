#include "food.hpp"
#include "snake.hpp"
#include <iostream>

Food::Food(Vector2& vec)
{
	x = vec.x;
	y = vec.y;
	eaten = false;
}

void Food::Draw()
{
	int row = 4 + y;
	int col = 1 + x;
	if (!eaten)
	{

	std::cout << "\033[" << row << ";" << col << "H" << std::flush;
	std::cout << "+" << std::flush;
	}
}

int Food::GetX()
{
	return x;
}

int Food::GetY()
{
	return y;
}

void Food::Ate()
{
	eaten = true;
}

