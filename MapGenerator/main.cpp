#include <iostream>
#include <cstdlib>
#include <ctime>
#include "main.h"
#include "room.h"
#include "cursor.h"
#include "define.h"

int main()
{
	srand(time(NULL));

	Room *test = new SquareRoom();
	RoomList *roomList = new RoomList();


#ifdef _WIN32
	system("mode con cols=200 lines=100");
	system("cls");
#elif __linux
	system("clear");
#endif

	for(int i =0; i<MAP_SIZE;i++)
	{
		for(int j=0;j<MAP_SIZE;j++)
		{
			std::cout<<"***";
		}
		std::cout<<std::endl;
	}

//	for(int i=0;i<MAP_SIZE;i++)
//		std::cout<<i<<std::endl;
	gotoxy(0,0);
	/*
	test->SetPosition();
	test->ShowRoom();


	test->GetRoom();

	((SquareRoom *)test)->GetPoint(1).GetPoint();
	*/

	roomList->SetRoomList();
	roomList->ShowRoomList();
	//roomList->GetRoomList();
}
