#include "Barbarian.h"

Barbarian::Barbarian() {
	m_id = -1;
	m_hp = new Hp(30);
	m_atk_interval = new Interval(60);
	m_atk_valid = new AttackRangeValidation(200);
	m_atk = new Attacking(16);
	m_pos = new Position();
	m_temp_pos = new Position();
	m_mov_valid = new MovementValidation();
	m_is_moving = true;
}

Barbarian::Barbarian(const int p_id, const POINT p_pos, const HWND p_hwnd) {
	//HDC h_dc, h_imgdc;
	//HBITMAP h_bit, h_oldbit;

	m_id = p_id;
	m_hp = new Hp(30);
	m_atk_interval = new Interval(800);
	m_atk_valid = new AttackRangeValidation(200);
	m_atk = new Attacking(16);
	m_pos = new Position(p_pos);
	m_temp_pos = new Position(p_pos);
	//h_dc = GetDC(p_hwnd);
	//h_imgdc = CreateCompatibleDC(h_dc);
	//h_bit = LoadBitmap(p_hinst, MAKEINTRESOURCE(IDB_BITMAP6));
	//h_oldbit = (HBITMAP)SelectObject(h_imgdc, h_bit);
	m_mov_valid = new MovementValidation(20, p_hwnd);
	//SelectObject(h_imgdc, h_oldbit);
	//DeleteObject(h_bit);
	//DeleteDC(h_imgdc);
	//ReleaseDC(p_hwnd, h_dc);
	m_is_moving = true;
}

Barbarian::~Barbarian() {
	if (m_hp != nullptr)			delete m_hp;
	if (m_atk_interval != nullptr)	delete m_atk_interval;
	if (m_atk_valid != nullptr)		delete m_atk_valid;
	if (m_atk != nullptr)			delete m_atk;
	if (m_pos != nullptr)			delete m_pos;
	if (m_temp_pos != nullptr)		delete m_temp_pos;
	if (m_mov_valid != nullptr)		delete m_mov_valid;
}

void Barbarian::render_unit(HINSTANCE p_hinst, HDC p_dc) {
	m_render.render_unit(p_hinst, p_dc, id_bm[2], m_pos->get_pos());
}

void Barbarian::move(const POINT p_target_pos) {
	m_mov_valid->temp_move(m_temp_pos->get_pos(), p_target_pos);
	if (m_mov_valid->validate_move(m_temp_pos->get_pos()) == false) {
		m_is_moving = m_movement.CancelMove(m_temp_pos->get_pos(), m_pos->get_pos());
		return;
	}
	m_is_moving = m_movement.Move(m_pos->get_pos(), m_temp_pos->get_pos());
}
//HINSTANCE, HDC, int, POINT, RECT

template <class Unit>
bool Barbarian::attack(Unit& p_target) {
	if ((m_atk_valid->is_in_range(m_pos->get_pos(), p_target.get_pos()) == false)) {
		m_atk_interval->validate_interval(false);
		return false;
	}
	if ((m_atk_interval->validate_interval(true)) == false) return true;
	p_target.take_dmg(m_atk->attack());
	return true;
}

template<class Unit>
void Barbarian::update(Unit& p_target, POINT p_pos) {
	if (attack(p_target) == true) return;
	move(p_pos);
}