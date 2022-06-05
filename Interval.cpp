#include "Interval.h"

Interval::Interval() {	//don't use
	m_tick = -1;
	m_start = clock();
	m_current = clock();
}

Interval::Interval(const int p_tick) {
	m_tick = p_tick;
	m_start = clock();
	m_current = clock();
}

Interval::~Interval() { }

//FSM 
bool Interval::validate_interval(const bool p_flag) {
	if (p_flag == false) {	//reset attack interval if not under engagement
		m_start = m_current = clock();
		return false;
	}
	m_current = clock();
	if (m_current - m_start < m_tick) return false;	//not enough interval
	m_start = m_current;	//reset attack interval for attacking
	return true;
}
