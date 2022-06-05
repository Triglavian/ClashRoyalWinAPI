#include "Attacking.h"

Attacking::Attacking() {
	m_dmg = -1;
}

Attacking::Attacking(const int p_dmg) {
	m_dmg = p_dmg;
}

Attacking::~Attacking() { }

template<class Target>
void Attacking::attack(Target* p_target) {
	p_target->m_hp->take_dmg(m_dmg);
}