#pragma once 
#include "snake.hpp"
#include "food.hpp"
#include <vector>

class Game
{
private:
    Snake snake;
    const int gridWidth = 20;
    const int gridHeight = 20;
    std::vector<Food> foods;
public:
    void Update();
    void Draw();
    void GameOver();
    void DrawGrid();
    void SpawnFood();
};
