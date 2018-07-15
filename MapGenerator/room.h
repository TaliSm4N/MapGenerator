#ifndef __ROOM_H__
#define __ROOM_H__

#include "define.h"

//use Point::Range(int mode,int p) for mode
#define HORIZON_MODE 0
#define VERTICAL_MODE 1

//방의 기준이 되는 포인트 클래스
class Point
{
private:
	int x;
	int y;
public:
	//한 변의 길이의 크기 조건 확인
	bool LineCheck(int line);
	//두 Point가 범위 안에 들어오는 지 확인
	bool RangeCheck(Point p);
	//한 번의 길이 체크
	bool RangeCheck(int mode, int p);
	//Point set
	void SetPoint();
	//매개변수 x,y를 기준으로 생성
	void SetPoint(int x, int y);
	void GetPoint();
	int GetX();
	int GetY();
};

//방의 부모 클래스
class Room
{
private:
	
public:
	virtual void SetPosition() {};
	virtual void GetPosition() {};
	virtual void GetRoom() {};
	virtual void ShowRoom(){};
};

//사각형 방의 클래스
class SquareRoom : public Room
{
private:
	Point p[2];
public:
	void SetPosition();
	void GetRoom();
	void ShowRoom();
};

//사각형 방이 아닌 방의 클래스
class IrreqularRoom : public Room
{
private:
	Point p[4];
public:
};

class RoomList
{
private:
	Room list[MAX_ROOM];
public:
	void ShowRoomList();
};

#endif