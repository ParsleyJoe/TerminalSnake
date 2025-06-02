#include "snake.hpp"
#include <iostream>
#include <unistd.h>

Snake::Snake()
{
	// start with 3 total segments (head included)
	AddBody();
	AddBody();
}

void Snake::Draw(int gridWidth, int gridHeight)
{
	// 4 and 1 get to first * printed in grid so
	// the first * printed is 0, 0 (origin)
	int row = 4 + y;
	int col = 1 + x;
	std::cout << "\033[" << row << ";" << col << "H" << std::flush;

	std::cout << "#" << std::flush;
	DrawBody();
}

void Snake::DrawBody()
{
	for (int i = 0; i < snakeBody.size(); ++i)
	{
		std::cout << "\033[H" << std::flush;
		int row = 4 + snakeBody[i].y;
		int col = 1 + snakeBody[i].x;
		std::cout << "\033[" << row << ";" << col << "H" << std::flush;
		std::cout << "#" << std::flush;
	}
}

void Snake::Move(int gridHeight, int gridWidth)
{
	// "Limit Movement"
	if ( x > gridWidth || y > gridHeight)
	{
		if ( x > gridWidth)
			x = 1;
		if ( y > gridHeight)
			y = 1;
		return;
	}
	if (x < 1 || y < 1)
	{	
		if ( x < 1)
			x = gridWidth;
		if ( y < 1)
			y = gridHeight;
		return;
	}

	// Input
	char c;
	read(STDIN_FILENO, &c, 1);
	ChangeDir(c);
	

	// Moves according to direction
	switch (dir) 
	{
		case direction::UP:
			y--;
			break;
		case direction::DOWN:
			y++;
			break;
		case direction::LEFT:
			x--;
			break;
		case direction::RIGHT:
			x++;
			break;
		default:
			std::cout << "ERROR direction isn't a valid enum" << std::flush;
			break;
	}
	MoveBody(gridWidth, gridHeight);
}

// Change dir for body and head
void Snake::ChangeDir(char input)
{
	// input to change direction
	switch (input)
	{
		case 'a':
		if (dir == direction::RIGHT) break;
			dir = direction::LEFT;
			changePos.push_back({x, y, dir});
			break;
		case 'd':
		if (dir == direction::LEFT) break;
			dir = direction::RIGHT;
			changePos.push_back({x, y, dir});
			break;
		case 's':
		if (dir == direction::UP) break;
			dir = direction::DOWN;
			changePos.push_back({x, y, dir});
			break;
		case 'w':
		if (dir == direction::DOWN) break;
			dir = direction::UP;
			changePos.push_back({x, y, dir});
			break;
	}

	// Change bodies direction while not breaking
	for (Vector2& vec : snakeBody)
	{
		for (int i = 0; i < changePos.size(); i++)
		{
			if (changePos[i].x == vec.x && changePos[i].y == vec.y && vec.dir != changePos[i].dir)
			{
				// If changePos == vecPos dir != what it should be
				vec.dir = changePos[i].dir;
				Vector2& back = snakeBody.back();
				if (changePos[i].x == back.x && changePos[i].y == back.y && changePos[i].dir == back.dir)
				{
					auto it = changePos.begin() + i;
					changePos.erase(it);
				}
			}
		}
	}

	// Clear changePos Vector2 if all segments of body "used" that vector2
	bool equal = true;
	//for (int i = 0; i < snakeBody.size(); i++)
	//{
	//Vector2 segement = snakeBody.back();
	// Vector2 pos = changePos.back();
	//if (snakeBody.back().dir != changePos.back().dir)
	//	equal = false;
	//}
	//if (equal)
		//changePos.clear();
}

void Snake::MoveBody(int gridWidth, int gridHeight)
{
	for (Vector2& vec : snakeBody)
	{
		switch(vec.dir)
		{
			case direction::DOWN:
				++vec.y;
				break;
			case direction::UP:
				--vec.y;
				break;
			case direction::LEFT:
				--vec.x;
				break;
			case direction::RIGHT:
				++vec.x;
				break;
		}
	}

	// Limit movement "From one side to another"
	for (Vector2& vec : snakeBody)
	{
		if ( vec.x > gridWidth || vec.y > gridHeight)
		{
			if ( vec.x > gridWidth)
				vec.x = 1;
			if ( vec.y > gridHeight)
				vec.y = 1;
			return;
		}
		if (vec.x < 1 || vec.y < 1)
		{	
			if ( vec.x < 1)
				vec.x = gridWidth;
			if ( vec.y < 1)
				vec.y = gridHeight;
			return;
		}
	}
}


bool Snake::isAlive()
{
    return alive;
}

bool Snake::BitItself()
{
	for (Vector2& vec : snakeBody)
	{
		if (x == vec.x && y == vec.y)
			return true;
	}
	return false;
}

bool Snake::CheckCollision(int otherX, int otherY)
{
	// Food
	if ( x == otherX && y == otherY)
	{
		AddBody();
		return true;
	}
	return false;
}

void Snake::AddBody()
{
	Vector2 end = Vector2 {x, y, dir};
	if (!snakeBody.empty())
		end = snakeBody.back();

	switch(end.dir)
	{
		case direction::DOWN:
			snakeBody.push_back(Vector2{end.x, end.y - 1, end.dir});
			break;
		case direction::UP:
			snakeBody.push_back(Vector2{end.x, end.y + 1, end.dir});
			break;
		case direction::LEFT:
			snakeBody.push_back(Vector2{end.x + 1, end.y, end.dir});
			break;
		case direction::RIGHT:
			snakeBody.push_back(Vector2{end.x - 1, end.y, end.dir});
			break;
	}
}
