#pragma once	
#include "BaseUnit.h"

class Attacking {
private:
	int m_dmg;
public:
	Attacking();			
	Attacking(const int);
	~Attacking(); 
	int attack();	//using template and call target's get_damage func
};