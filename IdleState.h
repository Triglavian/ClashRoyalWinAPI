#pragma once
#include "BaseState.h"

class IdleState : protected BaseState {
private:
public:
	void update(BaseUnit&, LPARAM);
	void action();
};

