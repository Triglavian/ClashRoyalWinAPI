#include "AttackRangeValidation.h"

AttackRangeValidation::AttackRangeValidation() {	//do not use
	m_range = -1;
}

AttackRangeValidation::AttackRangeValidation(const int p_range) {	//use this
	m_range = p_range;
}

AttackRangeValidation::~AttackRangeValidation() { }

bool AttackRangeValidation::is_in_range(const POINT p_pos1, const POINT p_pos2) {	//validate is the target in range
	return (m_range >= sqrt((pow((double)p_pos1.x - (double)p_pos2.x, 2) +
		pow((double)p_pos1.y - (double)p_pos2.y, 2))));
}