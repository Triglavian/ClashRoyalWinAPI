#include "MovementValidation.h"

MovementValidation::MovementValidation() {	//do not use
	m_speed = 0;
	m_rad = 0;
	m_distance = 0;
	m_window = { 0, 0, 0, 0 };	
}

MovementValidation::MovementValidation(int p_speed, HWND p_hwnd) {	//use this
	m_speed = p_speed;
	m_rad = 0;
	m_distance = 0;
	GetClientRect(p_hwnd, &m_window);
	//playable area
	m_window.left += 50;
	m_window.top += 50;
	m_window.right -= 50;
	m_window.bottom = 450;
}

MovementValidation::~MovementValidation() { }

void MovementValidation::temp_move(POINT& p_unit_temp_pos, const POINT p_target_pos) {	//temp move toward target
	get_distance(p_unit_temp_pos, p_target_pos);
	get_rad(p_unit_temp_pos, p_target_pos);
	if (m_distance > m_speed) {
		p_unit_temp_pos.x += (LONG)(m_speed * cos(m_rad));
		p_unit_temp_pos.y += (LONG)(m_speed * sin(m_rad));
	} else {
		p_unit_temp_pos = p_target_pos;
	}
}

bool MovementValidation::validate_move(const POINT p_unit_temp_pos) {	//validate is temp move in playable area
	return !(p_unit_temp_pos.x < m_window.left	||
		p_unit_temp_pos.x > m_window.right		||
		p_unit_temp_pos.y < m_window.top		||
		p_unit_temp_pos.y > m_window.bottom);
}

void MovementValidation::get_rad(const POINT p_pos1, const POINT p_pos2) {	//get rad by each side
	m_rad = atan2((double)(p_pos2.y - p_pos1.y), (double)(p_pos2.x - p_pos1.x));
}

void MovementValidation::get_distance(const POINT p_pos1, const POINT p_pos2) {	//get distance btw both pos
	m_distance = sqrt(pow((double)p_pos1.x - (double)p_pos2.x, 2) + pow((double)p_pos1.y - (double)p_pos2.y, 2));
}