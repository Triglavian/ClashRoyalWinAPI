#pragma once
#include <Windows.h>

class Movement {
private:
public:
	Movement();
	~Movement();
	bool Move(POINT&, const POINT);		//confirm modif pos to current pos
	bool CancelMove(POINT&, const POINT);	//reset modif pos to current pos
};