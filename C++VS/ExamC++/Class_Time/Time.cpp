#include "Time.h"
#include<iostream>

using namespace mayTime;

TTime::TTime(int Hour, int Minute, int Second)
{
	hour = Hour;
	minute = Minute;
	second = Second;
}

void TTime::SetTime(int Hour, int Minute, int Second)
{
	hour = Hour;
	minute = Minute;
	second = Second;
}

void  TTime::SetHour(int Hour)
{
	hour = Hour;
}


void TTime::SetMinute(int Minute)
{
	minute = Minute;
}
void TTime::SetSecond(int Second)
{
	second = Second;
}

int TTime::GetHour() const
{
	return hour;
}
int TTime::GetMinute() const
{
	return minute;
}
int TTime::GetSecond() const
{
	return second;
}

void TTime::IncrementMinute(int Count)
{	
	hour += Count / 60;
	minute = (minute + Count) % 60;	
}

void TTime::PrintTime() const
{
	if (hour == 0)
		std::cout << "00";
	else 
		std::cout << hour;
	
	std::cout << ":";

	if (minute == 0)
		std::cout << "00";
	else
		std::cout << minute;

	std::cout << ":";

	if (second == 0)
		std::cout << "00";
	else
		std::cout << second;

}

TTime::~TTime()
{

}
