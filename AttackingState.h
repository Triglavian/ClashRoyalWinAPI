#pragma once
#include "BaseState.h"
#include "BaseUnit.h"

class AttackingState : protected BaseState {
private:
public:
	void update(BaseUnit&);
	void action(BaseUnit&);
};

