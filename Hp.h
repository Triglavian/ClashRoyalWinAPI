#pragma once
class Hp {
private:
	int m_hp;
public:
	Hp();
	Hp(int);
	~Hp();
	bool get_dmg(int);	//get damage and validate hp
	bool validate_hp();	//validate current hp is positive
};

