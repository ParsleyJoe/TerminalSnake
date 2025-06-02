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
    bool gameActive = true;
public:
    void Update(int* score);
    void Draw();
    void DrawGrid();
    void SpawnFood();
    void GameOver();
    bool isGameActive();

};
