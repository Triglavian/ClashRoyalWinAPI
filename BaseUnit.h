#pragma once
#include <Windows.h>
#include "Hp.h"
#include "resource.h"
#include "Position.h"
//#include "Rendering.h"

class BaseUnit {
protected:
	Hp* m_hp;
	Position* m_pos;
	Position* m_temp_pos;
	int m_id;
	//m_state
	//m_state_type
	//E_STATE m_state_type;
	//UnitState* m_state;

	//Rendering m_render;
public:
	int get_hp();		//get current unit's hp
	POINT get_pos();	//get current unit's pos
	void set_pos(const POINT);
	POINT get_temp_pos();
	void set_temp_pos(const POINT);
	void take_dmg(const int);

	//E_STATE get_state();
	//void set_state_type(const E_STATE);

	virtual void render_unit(HINSTANCE, HDC) = 0;
};

