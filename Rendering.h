#pragma once
#include <iostream>
#include <Windows.h>
#include "GlobalInstance.h"

class Rendering {
private:
public:
	Rendering();
	~Rendering();
	void render_unit(HINSTANCE, HDC, int, POINT);
	//param1 is output, param2 is x pos, param3 is y pos, param 4 is msg	
	//void buffering(HWND);
	//void draw_bitmap(HWND, int, int);
};