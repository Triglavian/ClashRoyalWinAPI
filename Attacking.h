#pragma once
class Attacking
{
private:
	int m_dmg;
public:
	Attacking();			
	Attacking(const int);
	~Attacking(); 
	void attack(int&);
	//template <class T>
	//void attack();
};

