#include <iostream>
#include <cstdlib>
#include "main.h"
#include "room.h"
#include "cursor.h"
#include "define.h"

int main()
{
	srand(time(NULL));

	SquareRoom *test = new SquareRoom();

	system("clear");
	/*
	gotoxy(10,10);
	std::cout<<"*";
	gotoxy(0,0);
	std::cout<<"#";
	gotoxy(20,20);
	*/

	for(int i=0;i<MAP_SIZE;i++)
		std::cout<<i<<std::endl;
	gotoxy(0,0);

	test->SetPosition();
	test->ShowRoom();

	gotoxy(0,100);
	test->GetRoom();
}

