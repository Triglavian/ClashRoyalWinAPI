#pragma once
#include <vector>
#include "Archer.h"
#include "Barbarian.h"
#include "Tower.h"

#define CARD_ARCH 101
#define CARD_BARB 102

class UnitManager {
private:
	std::vector<Archer*> m_arch;
	std::vector<Barbarian*> m_barb;
	std::vector<Tower*> m_tower;
	int m_team;
public:
	UnitManager();
	UnitManager(int);
	~UnitManager();
	void CreateUnit(HWND, int, POINT);
	void update();
	void rendering(HINSTANCE, HDC);
};