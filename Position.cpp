#include "Position.h"

Position::Position() {
	m_pos = { 0, 0 };
}

Position::Position(POINT p_pos) {
	m_pos = p_pos;
}

Position::~Position() {

}

void Position::set_pos(POINT p_pos) {
	m_pos = p_pos;
}

POINT Position::get_pos() {
	return m_pos;
}
