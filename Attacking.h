#pragma once	

class Attacking {
private:
	int m_dmg;
public:
	Attacking();			
	Attacking(const int);
	~Attacking(); 
	template<class Target>
	void attack(Target*);	//using template and call target's get_damage func
};

