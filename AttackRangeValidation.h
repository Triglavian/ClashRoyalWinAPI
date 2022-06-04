#pragma once
#include <math.h>

class AttackRangeValidation {
private:
	int m_range;
public:
	AttackRangeValidation();
	AttackRangeValidation(const int);
	~AttackRangeValidation();
	bool is_in_range(int, int, int, int);
};