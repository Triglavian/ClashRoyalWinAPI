#pragma once
#include "AttackRangeValidation.h"
#include "Attacking.h"
#include "Interval.h"
#include "MovementValidation.h"
#include "Movement.h"
#include "Hp.h"
#include "resource.h"
#include "Position.h"
#include "Rendering.h"
#include "UnitState.h"
#include "EnumState.h"

class BaseUnit {
protected:

public:
	virtual void render_unit(HINSTANCE, HDC) = 0;

};

