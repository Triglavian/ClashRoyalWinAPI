#pragma once
#include <Windows.h>

class Movement {
private:
public:
	Movement();
	~Movement();
	void Move(POINT&, const POINT);		//confirm modif pos to current pos
	void CancelMove(POINT&, const POINT);	//reset modif pos to current pos
};