#include "Tower.h"

Tower::Tower() {
	m_id = -1;
	m_hp = new Hp(3000);
	m_atk_interval = new Interval(2000);
	m_atk_valid = new AttackRangeValidation(40);
	m_atk = new Attacking(40);
	m_pos = new Position({ 100, 100 });
	m_temp_pos = new Position({ 100, 100 });
	m_target = nullptr;
}

Tower::Tower(const int p_id, const POINT p_pos) {
	m_id = p_id;
	m_hp = new Hp(3000);
	m_atk_interval = new Interval(2000);
	m_atk_valid = new AttackRangeValidation(600);
	m_atk = new Attacking(40);
	m_pos = new Position(p_pos);
	m_temp_pos = new Position(p_pos);
	m_target = nullptr;
}

Tower::~Tower() {
	if (m_hp != nullptr)				delete m_hp;
	if (m_atk_interval != nullptr)	delete m_atk_interval;
	if (m_atk_valid != nullptr)		delete m_atk_valid;
	if (m_atk != nullptr)			delete m_atk;
	if (m_pos != nullptr)			delete m_pos;
	if (m_temp_pos != nullptr)		delete m_temp_pos;
}

int Tower::get_hp() {
	return m_hp->get_hp();
}

void Tower::render_unit(HINSTANCE p_hinst, HDC p_dc) {
	m_render.render_unit(p_hinst, p_dc, id_bm[m_id], m_pos->get_pos());
}

template <class Unit>
void Tower::set_target(std::vector<Unit*> p_unitlist) {
	for (auto item : p_unitlist) {
		if ((m_target == nullptr) || get_distance(get_pos(), m_target->get_pos()) > get_distance(get_pos(), item->get_pos())) {	//set target if target is not exist or new unit is closer than current target
			m_target = item;
		}
	}
}

bool Tower::attack() {
	if ((m_atk_valid->is_in_range(m_pos->get_pos(), m_target->get_pos()) == false)) {	//exception target is out of range
		m_atk_interval->validate_interval(false);	//reset attack tick
		return false;	//begin to move
	}
	if ((m_atk_interval->validate_interval(true)) == false) return true;	//exception attack tick not over, hold and wait to next attack
	m_target->take_dmg(m_atk->attack());
	return true;	//hold and wait no next attack
}

//void Tower::update(std::vector<Archer*> p_archer_list, std::vector<Barbarian*> p_barb_list, std::vector<Tower*> p_tower_list) {
//	set_target(p_archer_list);
//	set_target(p_barb_list);
//	set_target(p_tower_list);
//
//}