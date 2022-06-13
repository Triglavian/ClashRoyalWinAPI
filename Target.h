#pragma once
#include <vector>
#include <typeinfo>
#include <Windows.h>

class Target {
private:
	double m_distance;
	double m_temp_dist;
	double get_distance(const POINT, const POINT);
public:
	Target();
	~Target();
	void* m_target;
	template<class Unit>
	void get_closest_unit(std::vector<Unit*>, const POINT);
	//void* get_target();
};

