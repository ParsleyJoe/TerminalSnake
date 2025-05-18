#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include "game.hpp"

#define BOLDTEXT "\033[1;31mRed Text\033[0m\n"
#define CLEARSCREEN std::cout << "\033[2J\033[1;1H" << std::flush;

struct termios origTermios;

void die(const char *s)
{
	perror(s);
	exit(1);
}

void disableRawMode()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &origTermios);
}

void enableRawMode()
{
	tcgetattr(STDIN_FILENO, &origTermios);
	atexit(disableRawMode);

	struct termios raw = origTermios;
	raw.c_iflag &= ~(IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


int main()
{
	CLEARSCREEN;
	
	Game game;
	enableRawMode();
	while (1) 
	{
		// Game Loop 'q to quit'
		char c = '\0';
		read(STDIN_FILENO, &c, 1);
		if (c == 'q') break;

		// Sleep so drawing isn't too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		game.Update();
		
		// "UI" should move this in a class or something
		CLEARSCREEN;
		std::cout << "\033[1;31mASCII Snake\033[0m\n" << "\r\n";
		std::cout << "Game" << "\r\n";

		game.Draw();
	}
	return 0;
}
