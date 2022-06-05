#pragma once

class Hp {
private:
	int m_hp;
public:
	Hp();
	Hp(int);
	~Hp();
	void take_dmg(const int);	//take damage
	bool validate_hp();	//validate current hp is positive
	int get_hp();		//get remain hp
};

