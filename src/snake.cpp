#include "snake.hpp"
#include <iostream>
#include <unistd.h>

Snake::Snake()
{
	AddBody();
	AddBody();
	AddBody();

}

void Snake::Draw()
{
	for (int i = 0; i < snakeBody.size(); i++)
	{
		int row = 4 + snakeBody[i].y;
		int col = 1 + snakeBody[i].x;
	

		std::cout << "\033[" << row << ";" << col << "H" << std::flush;
		std::cout << "#" << std::flush;
	}
}

void Snake::Move(int gridWidth, int gridHeight)
{
	Vector2 newHead = {0};
	if (!snakeBody.empty())
		newHead = snakeBody.back();
	else
	{
		std::cerr << "Unexpected Error SnakeBody Empty" << std::endl;
		return;
	}

	Input();
	switch(dir)
	{
		case direction::DOWN:
			newHead.y++;
			break;
		case direction::UP:
			newHead.y--;
			break;
		case direction::LEFT:
			newHead.x--;
			break;
		case direction::RIGHT:
			newHead.x++;
			break;
	}

	// "Limit Movement"
	if ( newHead.x > gridWidth || newHead.y > gridHeight)
	{
		if ( newHead.x > gridWidth)
			newHead.x = 1;
		if ( newHead.y > gridHeight)
			newHead.y = 1;
	}
	if (newHead.x < 1 || newHead.y < 1)
	{	
		if ( newHead.x < 1)
			newHead.x = gridWidth;
		if ( newHead.y < 1)
			newHead.y = gridHeight;
	}
	snakeBody.pop_front();
	BitItself(newHead);
	snakeBody.push_back(newHead);

}

void Snake::Input()
{
	char c;
	read(STDIN_FILENO, &c, 1);

	switch (c) 
	{
		case 's':
		if (dir == direction::UP) {return;}
			dir = direction::DOWN;
			break;
		case 'w':
		if (dir == direction::DOWN) {return;}
			dir = direction::UP;
			break;
		case 'a':
		if (dir == direction::RIGHT) {return;}
			dir = direction::LEFT;
			break;
		case 'd':
		if (dir == direction::LEFT) {return;}
			dir = direction::RIGHT;
			break;
	}

}

bool Snake::CheckFoodCollision(int otherX, int otherY)
{
	Vector2 head;
	if (!snakeBody.empty())
		head = snakeBody.back();
	else
		std::cerr << "BODY Empty, IN checkfoodCollision" << std::endl;

	if (head.x == otherX && head.y == otherY)
	{
		AddBody();
		return true;
	}
	return false;
}

void Snake::AddBody()
{
	Vector2 tail;
	if (!snakeBody.empty())
		tail = snakeBody.front();

	switch(tail.dir)
	{
		case direction::DOWN:
			tail.y++;
			break;
		case direction::UP:
			tail.y--;
			break;
		case direction::LEFT:
			tail.x--;
			break;
		case direction::RIGHT:
			tail.x++;
			break;
	}
	snakeBody.push_front(tail);
}

void Snake::BitItself(Vector2& newHead)
{
	Vector2 head = {0};
	if (!snakeBody.empty())
		head = snakeBody.back();
	else
	{
		std::cerr << "Unexpected Error SnakeBody Empty" << std::endl;
	}

	for (int i = 1; i < snakeBody.size(); i++)
	{
		if (newHead.x == snakeBody[i].x && newHead.y == snakeBody[i].y)
		{
			alive = false;
		}
	}
}

bool Snake::isAlive()
{
	return alive;
}