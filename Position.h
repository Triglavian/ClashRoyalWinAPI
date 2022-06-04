#pragma once
#include <Windows.h>

class Position {
private:
	POINT m_pos;
public:
	Position();
	Position(POINT);
	~Position();
	void set_pos(POINT);
	POINT get_pos();
};

