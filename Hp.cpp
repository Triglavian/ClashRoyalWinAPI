#include "Hp.h"

Hp::Hp() {
    m_hp = 0;
}

Hp::Hp(int p_hp) {
    m_hp = p_hp;
}

Hp::~Hp() {

}

void Hp::take_dmg(const int p_dmg) {  //take damage
    m_hp -= p_dmg;
}

bool Hp::validate_hp() {    //validate current hp is positive, return if positive hp
    return (m_hp > 0);
}

int Hp::get_hp() {  //get remain hp
    return m_hp;
}
