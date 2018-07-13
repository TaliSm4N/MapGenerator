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



//���� ������ �Ǵ� ����Ʈ Ŭ����
class Point
{
private:
	int x;
	int y;
public:

	//�� ���� ������ ũ�� ���� Ȯ��
	bool LineCheck(int line)
	{
		if (line >= MIN_SIZE && line <= MAX_SIZE)
			return true;

		return false;
	}

	//�� Point�� ���� �ȿ� ������ �� Ȯ��
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

	//�� ���� ���� üũ
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

//���� �θ� Ŭ����
class Room
{
private:
	
public:
	virtual void setPosition() {};
	virtual void GetPosition() {};
};

//�簢�� ���� Ŭ����
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

//�簢�� ���� �ƴ� ���� Ŭ����
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