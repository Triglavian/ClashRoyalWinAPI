#pragma once
#include "BaseUnit.h"
#include "Interval.h"
#include "AttackRangeValidation.h"
#include "Attacking.h"
#include "Rendering.h"

class Tower : protected BaseUnit {
private:
	Interval* m_atk_interval;
	AttackRangeValidation* m_atk_valid;
	Attacking* m_atk;

	Rendering m_render;
	const int id_bm[2] = { IDB_BITMAP7, IDB_BITMAP8 };
public:
	Tower();
	Tower(const int, const POINT);
	~Tower();
	void attack(BaseUnit&);		//target 

	//E_STATE get_state();
	//void set_state_type(const E_STATE);

	void render_unit(HINSTANCE, HDC);
};

