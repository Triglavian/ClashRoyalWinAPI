#include "Movement.h"

Movement::Movement() { 
	m_speed = 0;
}

Movement::~Movement() { }

void Movement::Move(POINT& p_unit_pos, const POINT p_target_pos) {
	p_unit_pos = p_target_pos;
}

void Movement::CancelMove(POINT& p_target_pos, const POINT p_unit_pos) {
	p_target_pos = p_unit_pos;
}