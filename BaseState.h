#pragma once
#include <Windows.h>
#include "BaseUnit.h"

class BaseState {
protected:
	static HWND m_hwnd;
	static HINSTANCE m_hinst;
public:
	virtual void update(BaseUnit&, LPARAM) = 0;
	virtual void action() = 0;
};

