#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define MAX_ROOM 16
#define MAP_SIZE 100
#define MAX_SIZE 6
#define MIN_SIZE 3


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
	bool LineCheck(int line)
	{
		if (line >= MIN_SIZE && line <= MAX_SIZE)
			return true;

		return false;
	}

	//두 Point가 범위 안에 들어오는 지 확인
	bool RangeCheck(Point p)
	{
		int horizontal = abs(this->x - p.x);
		int vertical = abs(this->y - p.y);

		if (LineCheck(horizontal)&& LineCheck(vertical))
		{
			return true;
		}

		return false;
	}

	//한 번의 길이 체크
	bool RangeCheck(int mode, int p)
	{
		int range;

		if (mode == 0)
		{
			range = abs(this->x - p);
		}
		else
		{
			range = abs(this->y - p);
		}
		
		if (LineCheck(range))
		{
			return true;
		}
		
		return false;
	}

	//Point set
	void setPoint()
	{
		this->x = rand() % MAP_SIZE;
		this->y = rand() % MAP_SIZE;
	}

	void getPoint()
	{
		std::cout << "X: " << this->x << ", Y: " << this->y << std::endl;
	}
};

//방의 부모 클래스
class Room
{
private:
	
public:
	virtual void setPosition() {};
	virtual void GetPosition() {};
};

//사각형 방의 클래스
class SquareRoom : public Room
{
private:
	Point p[2];
public:
	void setPosition()
	{

		do
		{
		} while (1);

	}
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
	void ShowRoom()
	{
	}
};

int main()
{
	srand(time(NULL));
}