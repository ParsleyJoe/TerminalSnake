#pragma once 
#include "snake.hpp"
#include "food.hpp"

class Game
{
private:
    Snake snake;
    const int gridWidth = 20;
    const int gridHeight = 20;
    Food food = Food(gridWidth, gridHeight);
public:
    void Update();
    void Draw();
    void GameOver();
    void DrawGrid();
};
