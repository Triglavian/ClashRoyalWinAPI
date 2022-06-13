#pragma once
#include "BaseUnit.h"
#include "Tower.h"
#include "AttackRangeValidation.h"
#include "Attacking.h"
#include "Interval.h"
#include "MovementValidation.h"
#include "Movement.h"
#include "Hp.h"
#include "resource.h"
#include "Position.h"
#include "Rendering.h"

class Archer : public BaseUnit {
private:
	Interval* m_atk_interval;
	AttackRangeValidation* m_atk_valid;
	Attacking* m_atk;
	MovementValidation* m_mov_valid;
	Movement m_movement;
	Tower* m_target;

	Rendering m_render;
	const int id_bm[3] = { IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP3 };
	void move();	//move unit if do not attack now
	void set_target(std::vector<Tower*>);
	bool attack();		//target 
public:
	Archer();
	Archer(const int, const POINT, const HWND);
	~Archer();

	void update(std::vector<Tower*>);
	void render_unit(HINSTANCE, HDC);
};