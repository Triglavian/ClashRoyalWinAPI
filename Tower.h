#pragma once
#include "BaseUnit.h"
#include "Interval.h"
#include "AttackRangeValidation.h"
#include "Attacking.h"
#include "Rendering.h"

class Tower : public BaseUnit {
private:
	Interval* m_atk_interval;
	AttackRangeValidation* m_atk_valid;
	Attacking* m_atk;

	//Target* m_target;
	Rendering m_render;
	const int id_bm[2] = { IDB_BITMAP7, IDB_BITMAP8 };
	template <class Unit>
	void set_target(std::vector<Unit*>);
	bool attack();		//target 
	BaseUnit* m_target;
public:
	Tower();
	Tower(const int, const POINT);
	~Tower();

	//E_STATE get_state();
	//void set_state_type(const E_STATE);
	//void update(std::vector<Archer*>, std::vector<Barbarian*>, std::vector<Tower*>);
	int get_hp();
	void render_unit(HINSTANCE, HDC);
};