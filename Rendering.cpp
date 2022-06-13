#include "Rendering.h"

Rendering::Rendering() { 

}

Rendering::~Rendering() { 

}

void Rendering::render_unit(HINSTANCE p_hinst, HDC p_dc, int p_rsc, POINT p_pos) {
	HDC h_imgdc;
	HBITMAP h_bit, h_oldbit;
	BITMAP bit;
	h_imgdc = CreateCompatibleDC(p_dc);
	h_bit = LoadBitmap(p_hinst, MAKEINTRESOURCE(p_rsc));
	GetObject(h_bit, sizeof(BITMAP), &bit);
	h_oldbit = (HBITMAP)SelectObject(h_imgdc, h_bit);
	BitBlt(p_dc, p_pos.x - (bit.bmWidth / 2), p_pos.y - (bit.bmHeight / 2), bit.bmWidth, bit.bmHeight, h_imgdc, 0, 0, SRCCOPY);
	SelectObject(h_imgdc, h_oldbit);
	DeleteObject(h_bit);
} 