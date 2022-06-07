#pragma once
#include "BaseState.h"

class AttackingState : protected BaseState {
private:
public:
	void update(BaseUnit&, LPARAM);
	void action();
};

