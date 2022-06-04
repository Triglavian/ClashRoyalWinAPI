#include "MovementValidation.h"

MovementValidation::MovementValidation() {	//do not use
	m_speed = 0;
	m_rad = 0;
	m_distance = 0;
	m_window = { 0, 0, 0, 0 };	
	m_area = { 0, 0, 0, 0 };
}

MovementValidation::MovementValidation(int p_speed, HWND p_hwnd, HBITMAP h_bit) {	//use this
	m_speed = p_speed;
	m_rad = 0;
	m_distance = 0;
	GetClientRect(p_hwnd, &m_window);
	//playable area
	m_window.left += 50;
	m_window.top += 50;
	m_window.right -= 50;
	m_window.bottom = 450;
	BITMAP bit;
	GetObject(h_bit, sizeof(BITMAP), &bit);
	m_area = { -(bit.bmWidth / 2), -(bit.bmHeight / 2), bit.bmWidth / 2, bit.bmHeight / 2 };
}

MovementValidation::~MovementValidation() { }

void MovementValidation::get_rad(const POINT p_pos1, const POINT p_pos2) {	//get rad by each side
	m_rad = atan((double)(p_pos1.x - p_pos2.x) / (double)(p_pos1.y - p_pos2.y));
}

void MovementValidation::get_distance(const POINT p_pos1, const POINT p_pos2) {	//get distance btw both pos
	m_distance = sqrt(pow((double)p_pos1.x - (double)p_pos2.x, 2) + pow((double)p_pos1.y - (double)p_pos2.y, 2));
}

void MovementValidation::temp_move(POINT& p_unit_temppos, const POINT p_target_pos) {	//temp move toward target
	p_unit_temppos.x += m_distance * cos(m_rad);
	p_unit_temppos.y += m_distance * sin(m_rad);
}

bool MovementValidation::validate_move(const POINT p_unit_temp_pos) {	//validate is temp move in playable area
	return (p_unit_temp_pos.x + m_area.left < m_window.left		||
		p_unit_temp_pos.x + m_area.right	> m_window.right	||
		p_unit_temp_pos.y + m_area.top		< m_window.top		||
		p_unit_temp_pos.y + m_area.bottom	> m_window.bottom);
}