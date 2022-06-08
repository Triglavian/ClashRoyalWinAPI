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
	template <class Unit>
	bool attack(Unit&);		//target 
public:
	Tower();
	Tower(const int, const POINT);
	~Tower();

	//E_STATE get_state();
	//void set_state_type(const E_STATE);
	template <class Unit>
	void update(Unit&, POINT);
	void render_unit(HINSTANCE, HDC);
};