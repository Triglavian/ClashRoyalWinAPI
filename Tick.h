#pragma once
#include <ctime>

class Tick  {
private:
	clock_t m_tick;
	clock_t m_start_tick;
	clock_t m_current_tick;
public:
	Tick();
	Tick(const int);
	~Tick();
	bool is_tick();
};

