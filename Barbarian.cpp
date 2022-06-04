#include "Barbarian.h"

Barbarian::Barbarian() {
	m_hp = 60;
	m_atk_range = 1;
	m_dmg = 11;
	m_atk_speed = 800;
	m_move_speed = 200;
	m_x = 0;
	m_y = 0;
	m_modif_x = m_x;
	m_modif_y = m_y;
	m_atk_interval = new Interval(m_atk_speed);
	m_move_interval = new Interval(m_move_speed);
	m_atk_valid = new AttackRangeValidation(m_atk_range);
	m_atk = new Attacking(m_dmg);
}

Barbarian::Barbarian(int p_x, int p_y) {
	m_hp = 60;
	m_atk_range = 1;
	m_dmg = 11;
	m_atk_speed = 800;
	m_move_speed = 200;
	m_x = p_x;
	m_y = p_y;
	m_modif_x = m_x;
	m_modif_y = m_y;
	m_atk_interval = new Interval(m_atk_speed);
	m_move_interval = new Interval(m_move_speed);
	m_atk_valid = new AttackRangeValidation(m_atk_range);
	m_atk = new Attacking(m_dmg);
}

Barbarian::~Barbarian() { 
	delete m_atk_interval;
	delete m_atk_valid;
	delete m_atk;
}

int Barbarian::get_hp() {
	return m_hp;
}

int Barbarian::get_x() {
	return m_x;
}

int Barbarian::get_y() {
	return m_y;
}
	
//bool Barbarian::attack(const int p_target_x, const int p_target_y, int& p_target_hp) {
//	if (m_atk_valid->is_in_range(m_x, m_y, p_target_x, p_target_y) == false) {
//		m_atk_interval->validate_interval(false);	//reset attack interval
//		return false;
//	}
//	if (m_atk_interval->validate_interval(true) == false) return false;	//if not enough interval 
//	m_atk->attack(p_target_hp);
//	return true;
//}

void Barbarian::move(const int p_direction) {
	if (m_move_interval->validate_interval(true) == false) return;
	m_mov_valid.temp_move(m_modif_x, m_modif_y, p_direction);
	if (m_mov_valid.validate_movable(m_modif_x, m_modif_y) == false) {
		m_movement.CancelMove(m_x, m_y, m_modif_x, m_modif_y);
		return;
	}
	m_movement.Move(m_x, m_y, m_modif_x, m_modif_y);
}

//void Barbarian::set_movable(const bool p_movable) {
//	m_mov_valid.set_movable(p_movable);
//}
//
//bool Barbarian::get_movable() {
//	return m_mov_valid.get_movable();
//}


//Position& Barbarian::get_pos() {
//	return m_pos.get_pos();
//}

//template <class T>
//void Barbarian::attack(T p_target) {
//	if (m_atk_valid.is_in_range(m_x, m_y, p_target.get_x(), p_target.get_y()) == false) {
//		m_interval.validate_attack_interval(false);	//reset attack interval
//		return;
//	}
//	if (m_interval.validate_attack_interval(true) == false) return;	//if not enough interval 
//	m_atk.attack(p_target.get_hp());
//}
 