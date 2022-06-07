#pragma once
#include "BaseUnit.h"
#include "AttackRangeValidation.h"
#include "Attacking.h"
#include "Interval.h"
#include "MovementValidation.h"
#include "Movement.h"
#include "Hp.h"
#include "resource.h"
#include "Position.h"
#include "Rendering.h"
//#include "UnitState.h"
//#include "EnumState.h"

class Archer : public BaseUnit {
private:
	Interval* m_atk_interval;
	AttackRangeValidation* m_atk_valid;
	Attacking* m_atk;
	MovementValidation* m_mov_valid;
	Movement m_movement;

	bool m_is_moving;
	
	//m_state
	//m_state_type
	//E_STATE m_state_type;
	//UnitState* m_state;

	Rendering m_render;
	const int id_bm[3] = { IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP3 };
public:
	Archer();
	Archer(const int, const POINT, const HINSTANCE, const HWND);
	~Archer();
	void move(const POINT);	//move unit if movable
	bool attack(BaseUnit&);		//target 

	//E_STATE get_state();
	//void set_state_type(const E_STATE);

	void render_unit(HINSTANCE, HDC);
};