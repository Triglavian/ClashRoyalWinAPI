#include "UnitManager.h"

UnitManager::UnitManager() { }

UnitManager::UnitManager(int p_team) {
	m_team = p_team;
	switch (p_team) {
		case 0:	m_tower.push_back(new Tower(m_team, { 300, 225 }));
		case 1: m_tower.push_back(new Tower(m_team, { 800, 225 }));
	}
}


UnitManager::~UnitManager() {
	for (; m_arch.size() > 0; delete m_arch[0]);
	for (; m_arch.size() > 0; delete m_barb[0]);
	for (; m_arch.size() > 0; delete m_tower[0]);
}

void UnitManager::CreateUnit(HWND p_hwnd, int p_type, POINT p_cursor) {
	switch (p_type) {
		case CARD_ARCH:
			m_arch.push_back(new Archer(0, p_cursor, p_hwnd));
			break;
		case CARD_BARB:
			m_barb.push_back(new Barbarian(0, p_cursor, p_hwnd));
			break;
	}

}

void UnitManager::update() {
	for (auto item : m_arch) {
		item->update();
	}
	for (auto item : m_barb) {
		item->update();
	}
	for (auto item : m_tower) {
		item->update();
	}
}

void UnitManager::rendering(HINSTANCE p_hinst, HDC p_dc) {
	for (auto item : m_arch) {
		item->render_unit(p_hinst, p_dc);
	}
	for (auto item : m_barb) {
		item->render_unit(p_hinst, p_dc);
	}
	for (auto item : m_tower) {
		item->render_unit(p_hinst, p_dc);
	}
}