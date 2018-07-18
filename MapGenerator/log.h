#ifndef __LOG_H__
#define __LOG_H__

#include <fstream>

class Log
{
private:
	std::string name;
	std::ofstream fd;
public:
	Log(std::string filename);
	void WriteLog(std::string msg);
	~Log();
};

#endif