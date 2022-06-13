#include "Archer.h"

Archer::Archer() {
	m_id = -1;
	m_hp = new Hp(30);
	m_atk_interval = new Interval(800);
	m_atk_valid = new AttackRangeValidation(500);
	m_atk = new Attacking(16);	
	m_pos = new Position();
	m_temp_pos = new Position();
	m_mov_valid = new MovementValidation();
	m_target = nullptr;
}

Archer::Archer(int p_id, POINT p_pos, HWND p_hwnd) {
	m_id = p_id;
	m_hp = new Hp(30);
	m_atk_interval = new Interval(800);
	m_atk_valid = new AttackRangeValidation(500);
	m_atk = new Attacking(16);
	m_pos = new Position(p_pos);
	m_temp_pos = new Position(p_pos);
	m_mov_valid = new MovementValidation(20, p_hwnd);
	m_target = nullptr;
}

Archer::~Archer() {
	if (m_hp != nullptr)			delete m_hp;
	if (m_atk_interval != nullptr)	delete m_atk_interval;
	if (m_atk_valid != nullptr)		delete m_atk_valid;
	if (m_atk != nullptr)			delete m_atk;
	if (m_pos != nullptr)			delete m_pos;
	if (m_temp_pos != nullptr)		delete m_temp_pos;
	if (m_mov_valid != nullptr)		delete m_mov_valid;
	if (m_target != nullptr)		delete m_target;
}

void Archer::render_unit(HINSTANCE p_hinst, HDC p_dc) {
	m_render.render_unit(p_hinst, p_dc, id_bm[2], m_pos->get_pos());
}

void Archer::move() {
	m_mov_valid->temp_move(m_temp_pos->get_pos(), m_target->get_pos());
	if (m_mov_valid->validate_move(m_temp_pos->get_pos()) == false) {	//exception dest is out of playable area
		m_movement.CancelMove(m_temp_pos->get_pos(), m_pos->get_pos());
		return;
	}
	m_movement.Move(m_pos->get_pos(), m_temp_pos->get_pos());
}

void Archer::set_target(std::vector<Tower*> p_unitlist) {
	for (auto item : p_unitlist) {
		if ((p_unitlist.size() <= 0) || get_distance(get_pos(), m_target->get_pos()) > get_distance(get_pos(), item->get_pos())) {	//set target if target is not exist or new unit is closer than current target
			m_target = item;
		}
	}
}

bool Archer::attack() {
	if ((m_atk_valid->is_in_range(m_pos->get_pos(), m_target->get_pos()) == false)) {	//exception target is out of range
		m_atk_interval->validate_interval(false);	//reset attack tick
		return false;	//begin to move
	}
	if ((m_atk_interval->validate_interval(true)) == false) return true;	//exception attack tick not over, hold and wait to next attack
	m_target->take_dmg(m_atk->attack());
	return true;	//hold and wait no next attack
}

void Archer::update(std::vector<Tower*> p_tower_list) {
	set_target(p_tower_list);
	if (attack() == true) return;	//exception attacking status, hold pos and wait next attack
	move();
}