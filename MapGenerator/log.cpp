#include <iostream>
#include "log.h"

Log::Log(std::string filename):name(filename)
{
	fd.open(name,std::ios::trunc);
}

void Log::WriteLog(std::string msg)
{
	std::string str = "LOG:";
	str+=msg;
	fd<<str<<std::endl;
}

Log::~Log()
{
	fd.close();
}