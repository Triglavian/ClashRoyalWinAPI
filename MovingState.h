#pragma once
#include "BaseState.h"

class MovingState : protected BaseState {
private:
public:
	void update(BaseUnit&);
	void action(BaseUnit&);
};

