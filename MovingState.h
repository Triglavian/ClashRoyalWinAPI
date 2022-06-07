#pragma once
#include "BaseState.h"
#include "MovementValidation.h"
#include "Movement.h"

class MovingState : protected BaseState {
private:
	MovementValidation* m_mov_valid;
	Movement m_movement;
public:
	void update(BaseUnit&, LPARAM);
	void action();
};

