#pragma once
#include <iostream>
#include "Tick.h"
//#include "Rendering.h"
#include "Archer.h"
#include "Barbarian.h"

class Service {
private:
	Barbarian* bar;
	Archer* arch;
	Tick* rend_tick;
	//Rendering render;
public:
	Service();
	~Service();
	void run();
	void calculation();
	void rendering();
};

