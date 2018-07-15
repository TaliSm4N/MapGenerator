#include <iostream>
#include "cursor.h"

void gotoxy(int x, int y)
{
	printf("\033[%d;%df",y,x);

	fflush(stdout);
}

void printColorString(int color, char *str)
{
	printf("\033[%dm%s\033[0m", color, str);
}