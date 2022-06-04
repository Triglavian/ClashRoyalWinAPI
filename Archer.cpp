#include "Archer.h"

Archer::Archer() {
	//m_hp = 30;
	//m_atk_range = 4;
	//m_dmg = 8;
	//m_atk_speed = 600;
	//m_move_speed = 300;
	//m_x = 0;
	//m_y = 0;
	//m_modif_x = m_x;
	//m_modif_y = m_y;
	m_hp = new Hp(30);
	m_atk_interval = new Interval(60);
	m_atk_valid = new AttackRangeValidation(50);
	m_atk = new Attacking(16);
	m_movement = new Movement()
}

Hp* m_hp;
Interval* m_atk_interval;
AttackRangeValidation* m_atk_valid;
Attacking* m_atk;
Movement m_movement;
MovementValidation m_mov_valid;

Archer::Archer(const int p_x, const int p_y) {
	m_hp = 30;
	m_atk_range = 4;
	m_dmg = 8;
	m_atk_speed = 600;
	m_move_speed = 300;
	m_x = p_x;
	m_y = p_y;
	m_modif_x = m_x;
	m_modif_y = m_y;
	m_atk_interval = new Interval(m_atk_speed);
	m_move_interval = new Interval(m_move_speed);
	m_atk_valid = new AttackRangeValidation(m_atk_range);
	m_atk = new Attacking(m_dmg);
}

Archer::~Archer() {
	delete m_atk_interval;
	delete m_atk_valid;
	delete m_atk;
}

int Archer::get_hp() {
	return m_hp;
}

int Archer::get_x() {
	return m_x;
}

int Archer::get_y() {
	return m_y;
}

#include "Rendering.h"

//bool Archer::attack(const int p_target_x, const int p_target_y, int& p_target_hp) {
//	Rendering temp;
//	if (m_atk_valid->is_in_range(m_x, m_y, p_target_x, p_target_y) == false) {
//		m_atk_interval->validate_interval(false);	//reset attack interval
//		return false;
//	}
//	if (m_atk_interval->validate_interval(true) == false) {
//		temp.cursor_pos(0, 20);
//		std::cout << m_atk_interval->m_start << ", " << m_atk_interval->m_current << std::endl;
//		return false;	//if not enough interval 
//	}
//	m_atk->attack(p_target_hp);
//	return true;
//}

void Archer::move(const int p_direction) {
	if (m_move_interval->validate_interval(true) == false) return;
	m_mov_valid.temp_move(m_modif_x, m_modif_y, p_direction);
	if (m_mov_valid.validate_movable(m_modif_x, m_modif_y) == false) {
		m_movement.CancelMove(m_x, m_y, m_modif_x, m_modif_y);
		return;
	}
	m_movement.Move(m_x, m_y, m_modif_x, m_modif_y);
}
//
//void Archer::set_movable(const bool p_movable) {
//	m_mov_valid.set_movable(p_movable);
//}
//
//bool Archer::get_movable() {
//	return m_mov_valid.get_movable();
//}
