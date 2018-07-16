#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include "room.h"
#include "cursor.h"

int Room::GetAttr()
{
	return attr;
}

//한 변의 길이의 크기 조건 확인
bool Point::LineCheck(int line) const
{
	if (line >= MIN_SIZE && line <= MAX_SIZE)
		return true;

	return false;
}

//두 Point가 범위 안에 들어오는 지 확인
bool Point::RangeCheck(Point &p) const
{
	int horizontal = abs(this->x - p.x)+1;
	int vertical = abs(this->y - p.y)+1;

	if (LineCheck(horizontal)&& LineCheck(vertical))
	{
		return true;
	}

	return false;
}

//한 번의 길이 체크
bool Point::RangeCheck(int mode, int p) const
{
	int range;

	if (mode == 0)
	{
		range = abs(this->x - p)+1;
	}
	else
	{
		range = abs(this->y - p)+1;
	}
		
	if (LineCheck(range))
	{
		return true;
	}
	
	return false;
}

//Point set
void Point::SetPoint()
{
	this->x = rand() % MAP_SIZE;
	this->y = rand() % MAP_SIZE;
}

//매개변수 x,y를 기준으로 생성
void Point::SetPoint(int x, int y)
{
	this->x = rand() % (MAP_SIZE-x)+x;
	this->y = rand() % (MAP_SIZE-y)+y;
}

void Point::GetPoint() const
{
	std::cout << "X: " << this->x << ", Y: " << this->y << std::endl;
}

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

void SquareRoom::SetPosition()
{
	//적절한 범위일 때까지 반복 실행
	do
	{
		p[0].SetPoint();
		p[1].SetPoint(p[0].GetX(),p[0].GetY());
	}while(!p[0].RangeCheck(p[1]));
}

void SquareRoom::GetRoom() const
{
	std::cout<<"p[0]"<<std::endl;
	std::cout<<"x: "<<p[0].GetX()<<", y: "<<p[0].GetY()<<std::endl;
	std::cout<<"p[1]"<<std::endl;
	std::cout<<"x: "<<p[1].GetX()<<", y: "<<p[1].GetY()<<std::endl;
	std::cout<<"horizontal: "<<p[1].GetX()-p[0].GetX()+1<<", vertical: "<<p[1].GetY()-p[0].GetY()+1<<std::endl;
}

void SquareRoom::ShowRoom() const
{
	int count=0;
	gotoxy(0,0);
	gotoxy(p[0].GetX(),p[0].GetY());

	for(int i=p[0].GetY();i<=p[1].GetY();i++)
	{
		
		for(int j=p[0].GetX();j<=p[1].GetX();j++)
		{
			if (count == 0 || i == p[1].GetY())
				std::cout << '#';
			else if (j == p[0].GetX() || j == p[1].GetX())
				std::cout << '#';
			else
				std::cout << '.';
		}
		//std::cout << i << std::endl;
		gotoxy(p[0].GetX(),i+1);
		count++;
	}

}

Point SquareRoom::GetPoint(int token) const
{
	if (token == 0)
		return p[0];
	else
		return p[1];
}

bool SquareRoom::LineOverlap(int mode, int start, int end) const
{
	return true;
}

bool SquareRoom::OverlapRoom(Room &other) const
{
	//비교 대상인 Room이 SquareRoom일 때
	if (other.GetAttr() == SQUARE_MODE)
	{
		SquareRoom temp = (SquareRoom &)other;
		if ((LINECHECK(X, temp, 0) || LINECHECK(X, temp, 1)) && (LINECHECK(Y, temp, 0) || LINECHECK(Y, temp, 1)))
		{
			return true;
		}
	}

	return false;
}

void RoomList::ShowRoomList()
{
	for (int i = 0; i < MAX_ROOM; i++)
	{
		//system("pause");
		if(list[i].GetAttr()==SQUARE_MODE)
			list[i].ShowRoom();
	}
}

void RoomList::SetRoomList()
{
	for (int i = 0; i < MAX_ROOM; i++)
	{
		list[i] = *(new SquareRoom());
		list[i].SetPosition();
		for (int j = 0; j < i; j++)
		{
			if (list[i].OverlapRoom(list[j]))
			{
				i--;
				break; 
			}
		}
	}
}

void RoomList::GetRoomList() const
{
	gotoxy(1, MAX_SIZE *2);
	for (int i = 0; i < MAX_ROOM; i++)
	{
		list[i].GetRoom();
	}
}