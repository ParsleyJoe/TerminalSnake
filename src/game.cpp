#include "game.hpp"
#include <iostream>

void Game::Update()
{
    snake.Move(gridHeight, gridWidth);
    if (!snake.isAlive())
        GameOver();
}

void Game::Draw()
{
    DrawGrid();
    snake.Draw(gridWidth, gridHeight);
}

void Game::GameOver()
{
	// TODO: Add Gameover logic
}

void Game::DrawGrid()
{
	for (int i = 0; i <= gridHeight + 1; ++i)
	{
		for (int j = 0; j <= gridWidth + 1; ++j)
		{
			if (j == 0 || j == gridWidth + 1)
				std::cout << '*';
			else if (i == 0 || i == gridHeight + 1)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << "\r\n";
	}
}

