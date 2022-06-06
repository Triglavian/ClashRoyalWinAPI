#pragma once
#include <functional>
#include <array>
#include "AttackingState.h"
#include "IdleState.h"
#include "MovingState.h"
#include "EnumState.h"
#include "BaseUnit.h"

class UnitState {
public:
	UnitState();
	UnitState();
	~UnitState();
	std::array<std::function<void(BaseUnit&, WPARAM)>, (int)E_STATE::E_MAX> fp_update;
	std::array<std::function<void(BaseUnit&)>, (int)E_STATE::E_MAX> fp_action;
private:
	E_STATE m_state;
	AttackingState* m_atk;
	IdleState* m_idle;
	MovingState* m_mov;
};

