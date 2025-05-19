#include "food.hpp"
#include <random>
#include <iostream>

Food::Food(int gridWidth, int gridHeight)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> xRange(1 ,gridWidth);
	std::uniform_int_distribution<std::mt19937::result_type> yRange(1, gridHeight);
	x = xRange(rng);
	y = yRange(rng);
	
	std::cout << "Food Position: " << x << " " << y << std::endl;
}
