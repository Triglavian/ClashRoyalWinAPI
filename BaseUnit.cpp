#include "BaseUnit.h"

BaseUnit::BaseUnit() {
	m_hp = nullptr;
	m_pos = nullptr;
	m_temp_pos = nullptr;
	m_id = -1;
}

BaseUnit::~BaseUnit() {
	if (m_hp != nullptr) delete m_hp;
	if (m_pos != nullptr) delete m_pos;
	if (m_temp_pos != nullptr) delete m_temp_pos;
}

double BaseUnit::get_distance(const POINT p_pos1, const POINT p_pos2) {
	return sqrt(pow((double)p_pos1.x - (double)p_pos2.x, 2) + pow((double)p_pos1.y - (double)p_pos2.y, 2));
}

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