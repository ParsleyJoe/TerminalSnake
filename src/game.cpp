#include "game.hpp"
#include <iostream>
#include <chrono>

void Game::Update()
{
    snake.Move(gridWidth, gridHeight);

    if (snake.CheckCollision(food.GetX(), food.GetY()))
		food.Ate();
    if (!snake.isAlive())
        GameOver();

    // // Record start time
    // auto start = std::chrono::high_resolution_clock::now();

    // // Record end time
    // auto end = std::chrono::high_resolution_clock::now();

    // // Calculate elapsed time	
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

void Game::Draw()
{
    DrawGrid();
    snake.Draw(gridWidth, gridHeight);
    food.Draw();
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

