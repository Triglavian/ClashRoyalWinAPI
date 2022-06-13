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
#include "Target.h"
#include "Tower.h"

class Barbarian : public BaseUnit {
private:
	Interval* m_atk_interval;
	AttackRangeValidation* m_atk_valid;
	Attacking* m_atk;
	MovementValidation* m_mov_valid;
	Movement m_movement;
	BaseUnit* m_target;

	//m_state
	//m_state_type
	//E_STATE m_state_type;
	//UnitState* m_state;

	Rendering m_render;
	const int id_bm[3] = { IDB_BITMAP4, IDB_BITMAP5, IDB_BITMAP6 };
	void move();	//move unit if movable
	void set_target(std::vector<Tower*>);
	bool attack();		//target 
public:
	Barbarian();
	Barbarian(const int, const POINT, const HWND);
	~Barbarian(); 

	//E_STATE get_state();
	//void set_state_type(const E_STATE);
	void update(std::vector<Tower*>);
	void render_unit(HINSTANCE, HDC);
};