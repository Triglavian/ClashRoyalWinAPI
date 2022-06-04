#include "AttackRangeValidation.h"

AttackRangeValidation::AttackRangeValidation() {
	m_range = -1;
}

AttackRangeValidation::AttackRangeValidation(const int p_range) {
	m_range = p_range;
}

AttackRangeValidation::~AttackRangeValidation() { }

bool AttackRangeValidation::is_in_range(int p_atker_x, int p_atker_y, int p_target_x, int p_target_y) {	
	//validate distance btw each obj is shorter than attack range
	return (m_range >= sqrt((pow((double)p_atker_x - (double)p_target_x, 2) + 
		pow((double)p_atker_y - (double)p_target_y, 2))));
}