#pragma once
#include <Windows.h>
#include "Hp.h"
#include "resource.h"
#include "Position.h"
#include <vector>	
//#include "Rendering.h"

class BaseUnit {
protected:
	Hp* m_hp;
	Position* m_pos;
	Position* m_temp_pos;
	int m_id;
	double get_distance(const POINT, const POINT);
public:
	BaseUnit();
	~BaseUnit();
	int get_hp();		//get current unit's hp
	POINT get_pos();	//get current unit's pos
	void set_pos(const POINT);
	POINT get_temp_pos();
	void set_temp_pos(const POINT);
	void take_dmg(const int);
};

