#include "Attacking.h"

Attacking::Attacking() {
	m_dmg = -1;
}

Attacking::Attacking(const int p_dmg) {
	m_dmg = p_dmg;
}

Attacking::~Attacking() { }

void Attacking::attack(int& p_target_hp) {
	p_target_hp -= m_dmg;
}