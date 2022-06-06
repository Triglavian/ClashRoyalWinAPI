#pragma once
#include "BaseUnit.h"

class Barbarian {
private:
	Hp* m_hp;
	Interval* m_atk_interval;
	AttackRangeValidation* m_atk_valid;
	Attacking* m_atk;
	Position* m_pos;
	Position* m_temp_pos;
	MovementValidation* m_mov_valid;
	Movement m_movement;
	bool m_is_moving;

	//m_state
	//m_state_type
	
	E_STATE m_state_type;
	UnitState* m_state;

	Rendering m_render;
	int id_bm[3] = { IDB_BITMAP4, IDB_BITMAP5, IDB_BITMAP6 };
public:	
	Barbarian();
	Barbarian(const POINT, const HINSTANCE, const HWND);
	~Barbarian();		
	int get_hp();		//get current unit's hp
	POINT get_pos();	//get current unit's pos
	void move(const POINT);	//move unit if movable
	void attack(BaseUnit*);	//target 

	E_STATE get_state();
	void set_state_type(const E_STATE);

	void render_unit(HINSTANCE, HDC);
};