#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "room.h"
#include "cursor.h"

//한 변의 길이의 크기 조건 확인
bool Point::LineCheck(int line)
{
	if (line >= MIN_SIZE && line <= MAX_SIZE)
		return true;

	return false;
}

//두 Point가 범위 안에 들어오는 지 확인
bool Point::RangeCheck(Point p)
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
bool Point::RangeCheck(int mode, int p)
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

void Point::GetPoint()
{
	std::cout << "X: " << this->x << ", Y: " << this->y << std::endl;
}

int Point::GetX()
{
	return x;
}

int Point::GetY()
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

void SquareRoom::GetRoom()
{
	std::cout<<"p[0]"<<std::endl;
	std::cout<<"x: "<<p[0].GetX()<<", y: "<<p[0].GetY()<<std::endl;
	std::cout<<"p[1]"<<std::endl;
	std::cout<<"x: "<<p[1].GetX()<<", y: "<<p[1].GetY()<<std::endl;
	std::cout<<"horizontal: "<<p[1].GetX()-p[0].GetX()+1<<", vertical: "<<p[1].GetY()-p[0].GetY()+1<<std::endl;
}

void SquareRoom::ShowRoom()
{
	gotoxy(0,0);
	gotoxy(p[0].GetX(),p[0].GetY());

	for(int i=p[0].GetY();i<=p[1].GetY();i++)
	{
		for(int j=p[0].GetX();j<=p[1].GetX();j++)
		{
			std::cout<<'#';
		}
		std::cout<<i<<std::endl;
		gotoxy(p[0].GetX(),i);
	}

}

void RoomList::ShowRoomList()
{

}