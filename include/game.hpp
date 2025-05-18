#pragma once 
#include "snake.hpp"


class Game
{
private:
    Snake snake;
    const int gridWidth = 20;
    const int gridHeight = 20;
public:
    void Update();
    void Draw();
    void GameOver();
    void DrawGrid();
};
