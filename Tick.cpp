#include "Tick.h"

Tick::Tick() {
	m_tick = 1;
	m_start_tick = 0;
	m_current_tick = 0;
}

Tick::Tick(const int p_tick) {
	m_tick = p_tick;
	m_start_tick = 0;
	m_current_tick = 0;
}

Tick::~Tick() { }

bool Tick::is_tick() {
	if (m_start_tick == m_current_tick) m_start_tick = clock();	//set new start tick if previous tick is over
	m_current_tick = clock();
	if (m_current_tick - m_start_tick < m_tick) return false;
	m_start_tick = m_current_tick;	//reset ticks if current tick is over;
	return true;
}
