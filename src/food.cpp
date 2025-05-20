#include "food.hpp"
#include <random>
#include <iostream>

Food::Food(int gridWidth, int gridHeight)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> xRange(1 ,gridWidth);
	//std::uniform_int_distribution<std::mt19937::result_type> yRange(1, gridHeight);
	x = xRange(rng);
	y = 1;//yRange(rng);
	
	std::cout << "Food Position: " << x << " " << y << std::endl;
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

