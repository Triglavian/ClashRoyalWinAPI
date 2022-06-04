#pragma once
#include "AttackRangeValidation.h"
#include "Attacking.h"
#include "Interval.h"
#include "MovementValidation.h"
#include "Movement.h"
#include "Hp.h"
#include "resource.h"

//#include "Rendering.h"

class Barbarian
{
private:
	int m_hp;
	int m_atk_range;
	int m_dmg;
	int m_atk_speed;
	int m_move_speed;
	int m_x;
	int m_y;
	int m_modif_x;
	int m_modif_y;	
	Interval* m_atk_interval;
	Interval* m_move_interval;
	AttackRangeValidation* m_atk_valid;
	Attacking* m_atk;
	Movement m_movement;
	MovementValidation m_mov_valid;
	//Rendering m_render;
public:	
	Barbarian();
	Barbarian(int, int);
	~Barbarian();
	int get_hp();
	int get_x();
	int get_y();
	//bool attack(const int, const int, int&);
	void move(const int);
};