#include "UnitState.h"

UnitState::UnitState() {
	m_state = E_STATE::E_IDLE;
	m_atk = new AttackingState();
	m_idle = new IdleState();
	m_mov = new MovingState();
	fp_update[0] = std::bind(&IdleState::update, m_idle, std::placeholders::_1);
	fp_update[1] = std::bind(&MovingState::update, m_mov, std::placeholders::_1);
	fp_update[2] = std::bind(&AttackingState::update, m_atk, std::placeholders::_1);
	fp_action[0] = std::bind(&IdleState::action, m_idle, std::placeholders::_1);
	fp_action[1] = std::bind(&MovingState::action, m_mov, std::placeholders::_1);
	fp_action[2] = std::bind(&AttackingState::action, m_atk, std::placeholders::_1);
}

UnitState::~UnitState() { }
