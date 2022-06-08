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

BaseUnit::BaseUnit()
{
}

void BaseUnit::set_temp_pos(const POINT p_pos) {
	m_temp_pos->set_pos(p_pos);
}

BaseUnit::~BaseUnit()
{
}

void BaseUnit::take_dmg(const int p_dmg) {
	m_hp->take_dmg(p_dmg);
}

void BaseUnit::render_unit(HINSTANCE p_hinst, HDC p_dc) {

}

template<class Unit> 
void BaseUnit::get_target(std::vector<Unit*> p_unit_list) {
	static double min_dist;
	double current_dist;
	for (auto item : p_unit_list) {
		current_dist = MovementValidation::get_distance(get_pos(), item->get_pos());
		if (current_dist < min_dist) min_dist = current_dist;

	}
}