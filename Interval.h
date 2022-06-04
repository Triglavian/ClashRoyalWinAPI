#pragma once
#include <ctime>

class Interval {
private:
public:
	int m_interval;	//ms
	int m_start;
	int m_current;
public:
	Interval();	//don't use
	Interval(const int);
	~Interval();
	bool validate_interval(const bool);	//validate attack speed
};