#include "BaseUnit.h"

int BaseUnit::get_hp() {	//get current unit's hp
	return m_hp->get_hp();
}

POINT BaseUnit::get_pos() {	//get current unit's pos
	return m_pos->get_pos();
}

void BaseUnit::set_pos(const POINT p_pos) {
	m_pos->set_pos(p_pos);
}

POINT BaseUnit::get_temp_pos() {
	return m_temp_pos->get_pos();
}

void BaseUnit::set_temp_pos(const POINT p_pos) {
	m_temp_pos->set_pos(p_pos);
}

void BaseUnit::take_dmg(const int p_dmg) {
	m_hp->take_dmg(p_dmg);
}