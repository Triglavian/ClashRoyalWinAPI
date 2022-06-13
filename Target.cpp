#include "Target.h"

Target::Target() {
	m_target = nullptr;
	m_distance = -1;
	m_temp_dist = -1;
}

Target::~Target() { 
	if (m_target != nullptr) delete m_target;
}

//void* Target::get_target() {
//	auto unit = typeid(m_target).name();
//	return *((unit*)m_target);
//}

template<class Unit>
void Target::get_closest_unit(std::vector<Unit*> p_unit_list, const POINT p_pos) {
	if (m_target != nullptr) m_distance = get_distance(p_pos, m_target->get_pos());
	for (auto item : p_unit_list) {
		if (m_target == nullptr) {
			m_target = item;
			m_distance = get_distance(p_pos, m_target->get_pos());
			continue;
		}
		m_temp_dist = get_distance(p_pos, item->get_pos());
		if (m_temp_dist > m_distance) continue;
		m_target = item;
		m_distance = m_temp_dist;
	}
}

double Target::get_distance(const POINT p_pos1, const POINT p_pos2) {	//get distance btw both pos
	return sqrt(pow((double)p_pos1.x - (double)p_pos2.x, 2) + pow((double)p_pos1.y - (double)p_pos2.y, 2));
}