#include "Tower.h"

Tower::Tower() {
	m_id = -1;
	m_hp = new Hp(3000);
	m_atk_interval = new Interval(2000);
	m_atk_valid = new AttackRangeValidation(40);
	m_atk = new Attacking(40);
	m_pos = new Position({ 100, 100 });
	m_temp_pos = new Position({ 100, 100 });
}

Tower::Tower(const int p_id, const POINT p_pos) {
	m_id = p_id;
	m_hp = new Hp(3000);
	m_atk_interval = new Interval(2000);
	m_atk_valid = new AttackRangeValidation(40);
	m_atk = new Attacking(40);
	m_pos = new Position(p_pos);
	m_temp_pos = new Position(p_pos);
}

Tower::~Tower() {
	if (m_hp != nullptr)				delete m_hp;
	if (m_atk_interval != nullptr)	delete m_atk_interval;
	if (m_atk_valid != nullptr)		delete m_atk_valid;
	if (m_atk != nullptr)			delete m_atk;
	if (m_pos != nullptr)			delete m_pos;
	if (m_temp_pos != nullptr)		delete m_temp_pos;
}

void Tower::render_unit(HINSTANCE p_hinst, HDC p_dc) {
	m_render.render_unit(p_hinst, p_dc, id_bm[m_id], m_pos->get_pos());
}

template<class Unit>
bool Tower::attack(Unit& p_target) {
	if ((m_atk_valid->is_in_range(m_pos->get_pos(), p_target.get_pos()) == false)) {
		m_atk_interval->validate_interval(false);
		return false;
	}
	if ((m_atk_interval->validate_interval(true)) == false) return true;
	p_target.take_dmg(m_atk->attack());
	return true;
}

template<class Unit>
void Tower::update(Unit& p_target, POINT p_pos) {
	attack(p_target);
}