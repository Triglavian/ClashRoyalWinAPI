#pragma once
#include <Windows.h>
#include <cmath>

class MovementValidation {
private:
	int m_speed;
	double m_rad;
	double m_distance;
	RECT m_window;
	void get_rad(const POINT, const POINT);		//get rad by each side
	void get_distance(const POINT, const POINT);//get distance btw both pos
public:
	MovementValidation();	//do not use
	MovementValidation(int, HWND);	//use this
	~MovementValidation();
	void temp_move(POINT&, const POINT);	//temp move toward target
	bool validate_move(const POINT);		//validate is temp move in playable area
};