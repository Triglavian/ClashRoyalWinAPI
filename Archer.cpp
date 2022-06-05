#include "Archer.h"

Archer::Archer() {
	m_hp = new Hp(30);
	m_atk_interval = new Interval(60);
	m_atk_valid = new AttackRangeValidation(200);
	m_atk = new Attacking(16);	
	m_pos = new Position();
	m_temp_pos = new Position();
	m_mov_valid = new MovementValidation();
	m_is_moving = true;
}

Archer::Archer(const POINT p_pos, const HINSTANCE p_hinst, const HWND p_hwnd) {
	HDC h_dc, h_imgdc;
	HBITMAP h_bit, h_oldbit;

	m_hp = new Hp(30);
	m_atk_interval = new Interval(800);
	m_atk_valid = new AttackRangeValidation(200);
	m_atk = new Attacking(16);
	m_pos = new Position(p_pos);
	m_temp_pos = new Position(p_pos);
	h_dc = GetDC(p_hwnd);
	h_imgdc = CreateCompatibleDC(h_dc);
	h_bit = LoadBitmap(p_hinst, MAKEINTRESOURCE(IDB_BITMAP3));
	h_oldbit = (HBITMAP)SelectObject(h_imgdc, h_bit);
	m_mov_valid = new MovementValidation(20, p_hwnd, h_bit);
	SelectObject(h_imgdc, h_oldbit);
	DeleteObject(h_bit);
	DeleteDC(h_imgdc);
	ReleaseDC(p_hwnd, h_dc);
	m_is_moving = true;
}

Archer::~Archer() {
	delete m_hp;
	delete m_atk_interval;
	delete m_atk_valid;
	delete m_atk;
	delete m_pos;
	delete m_temp_pos;
	delete m_mov_valid;
}

int Archer::get_hp() {	//get current unit's hp
	return m_hp->get_hp();
}

POINT Archer::get_pos() {	//get current unit's pos
	return m_pos->get_pos();
}

void Archer::move(const POINT p_target_pos) {
	m_mov_valid->temp_move(m_temp_pos->get_pos(), p_target_pos);
	if (m_mov_valid->validate_move(m_temp_pos->get_pos()) == false) {
		m_is_moving = m_movement.CancelMove(m_temp_pos->get_pos(), m_pos->get_pos());
		return;
	}
	m_is_moving = m_movement.Move(m_pos->get_pos(), m_temp_pos->get_pos());
}
//HINSTANCE, HDC, int, POINT, RECT

void Archer::render_unit(HINSTANCE p_hinst, HDC p_dc) {
	m_render.render_unit(p_hinst, p_dc, id_bm[2], m_pos->get_pos());
}

template<class Target>
void Archer::attack(Target* p_target) {
	if ((m_atk_interval->validate_interval(true) ||	m_atk_valid->is_in_range(m_pos->get_pos(), p_target->m_pos->get_pos())) != true) return;
	this->m_atk->attack(p_target);
}