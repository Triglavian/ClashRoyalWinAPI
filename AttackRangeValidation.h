#pragma once
#include <math.h>
#include <Windows.h>

class AttackRangeValidation {
private:
	int m_range;
public:
	AttackRangeValidation();			//do not use
	AttackRangeValidation(const int);	//use this
	~AttackRangeValidation();
	bool is_in_range(const POINT, const POINT);	//validate is the target in range
};