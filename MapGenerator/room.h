#ifndef __ROOM_H__
#define __ROOM_H__

#include "define.h"
#include "log.h"

//use Point::Range(int mode,int p) for mode
#define HORIZON_MODE 0
#define VERTICAL_MODE 1

//use Room's attr
#define SQUARE_MODE 0
#define IRREGULAR_MODE 1

#define LINECHECK(z,t,n) ((p[0].Get##z()-2>=0?p[0].Get##z()-2:0) <= t.GetPoint(n).Get##z() && p[1].Get##z()+2 >= t.GetPoint(n).Get##z()||(t.GetPoint(0).Get##z()-2>=0?t.GetPoint(0).Get##z()-2:0) <= p[n].Get##z() && t.GetPoint(1).Get##z()+2 >= p[n].Get##z())

//방의 기준이 되는 포인트 클래스
class Point
{
private:
	int x;
	int y;
public:
	Point():x(0),y(0){};
	Point(int X, int Y):x(X),y(Y){};
	//한 변의 길이의 크기 조건 확인
	bool LineCheck(int line) const;
	//두 Point가 범위 안에 들어오는 지 확인
	bool RangeCheck(Point &p) const;
	//한 번의 길이 체크
	bool RangeCheck(int mode, int p) const;
	//Point set
	void SetPoint();
	//매개변수 x,y를 기준으로 생성
	void SetPoint(int x, int y);
	void GetPoint() const;
	int GetX() const;
	int GetY()const;


	Point operator=(const Point& right)
	{
		this->x = right.x;
		this->y = right.y;
	}
/*
	Point operator+(const Point& right)
	{
		int x = this.x + right.x;
		int y = this.y + right.y;
		return Point(x,y);
	}
	*/
};

//방의 부모 클래스
class Room
{
private:
protected:
	int attr;
public:
	virtual void SetPosition() {};
	virtual void GetPosition() const {};
	virtual void SetDoor(){};
	virtual void GetRoom() const {};
	virtual void ShowRoom() const{};
	virtual bool OverlapRoom(Room &other) const { return false; };

	int GetAttr();
};

//사각형 방의 클래스
class SquareRoom : public Room
{
private:
	Point p[2];
	Point door[4];
	int door_cnt;
public:
	SquareRoom():door_cnt(0) { attr=SQUARE_MODE;  };
	void SetPosition();
	void GetRoom() const;
	void ShowRoom() const;
	Point GetPoint(int token) const;
	bool LineOverlap(int mode, int start, int end) const;
	bool OverlapRoom(Room &other) const;
	void SetDoor();
	void GetDoorCnt() const;
	//void WriteLog(Log &l) const;
};

//사각형 방이 아닌 방의 클래스
class IrregularRoom : public Room
{
private:
	Point p[4];
public:
	IrregularRoom() { attr = IRREGULAR_MODE; };
};

class RoomList
{
private:
	SquareRoom *list[MAX_ROOM];
	//Log *roomLog;
public:
	RoomList();
	void ShowRoomList();
	void SetRoomList();
	void GetRoomList() const;
};

#endif
