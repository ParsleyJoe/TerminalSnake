#include "game.hpp"
#include "food.hpp"
#include <iostream>
#include <chrono>

void Game::Update(int* score)
{
    snake.Move(gridWidth, gridHeight);

	for (int i = 0; i < foods.size(); i++)
	{
    	if (snake.CheckFoodCollision(foods[i].GetX(), foods[i].GetY()))
		{
		 	foods[i].Ate();
		 	*score += 10;
		}
	}
    if (!snake.isAlive())
        GameOver();

    using namespace std::chrono_literals;
    // Record start time
    static auto start = std::chrono::high_resolution_clock::now();

    // Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate elapsed time	
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    if (duration >= 10000ms)
    {
		SpawnFood();
		duration = 0ms;
		start = std::chrono::high_resolution_clock::now();
    }
    
}

void Game::SpawnFood()
{
	Food food = Food(gridWidth, gridHeight);
	foods.push_back(food);
}


void Game::Draw()
{
    DrawGrid();
    snake.Draw();
    for (Food& food : foods)
	{
		food.Draw();
	}
}

void Game::GameOver()
{
	// TODO: Add Gameover logic
	gameActive = false;
}

bool Game::isGameActive() {return gameActive;}

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

