#pragma once
#include "AttackRangeValidation.h"
#include "Attacking.h"
#include "Interval.h"
#include "MovementValidation.h"
#include "Movement.h"
#include "Hp.h"
#include "resource.h"
#include "Position.h"
#include "Rendering.h"

//#include "Rendering.h"
class Barbarian;

class Archer {
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
	Rendering m_render;
	const int id_bm[3] = { IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP3 };
	
public:
	Archer();
	Archer(const POINT, const HINSTANCE, const HWND);
	~Archer();
	int get_hp();		//get current unit's hp
	POINT get_pos();	//get current unit's pos
	void move(const POINT);	//move unit if movable
	template <class Target>	
	void attack(Target*);	//target 
	void render_unit(HINSTANCE, HDC);
};