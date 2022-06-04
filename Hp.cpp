#include "Hp.h"

Hp::Hp() {
    m_hp = 0;
}

Hp::Hp(int p_hp) {
    m_hp = p_hp;
}

Hp::~Hp() {

}

bool Hp::get_dmg(int p_dmg) {
    m_hp -= p_dmg;
    return validate_hp();
}

bool Hp::validate_hp() {
    return (m_hp >= 0);
}
