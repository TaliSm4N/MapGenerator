#include <iostream>
#include "cursor.h"

#ifdef _WIN32

#include <Windows.h>

void gotoxy(int x, int y)
{
	COORD pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#elif __linux

void gotoxy(int x, int y)
{
	printf("\033[%d;%df",y,x);

	fflush(stdout);
}

void printColorString(int color, char *str)
{
	printf("\033[%dm%s\033[0m", color, str);
}

#endif