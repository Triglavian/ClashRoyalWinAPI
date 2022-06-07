#include "Attacking.h"

Attacking::Attacking() {
	m_dmg = -1;
}

Attacking::Attacking(const int p_dmg) {
	m_dmg = p_dmg;
}

Attacking::~Attacking() { }

int Attacking::attack() {
	return m_dmg;
}