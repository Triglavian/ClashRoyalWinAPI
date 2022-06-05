#include "Movement.h"

Movement::Movement() { }

Movement::~Movement() { }

bool Movement::Move(POINT& p_unit_pos, const POINT p_target_pos) {
	p_unit_pos = p_target_pos;
	return true;
}

bool Movement::CancelMove(POINT& p_target_pos, const POINT p_unit_pos) {
	p_target_pos = p_unit_pos;
	return false;
}