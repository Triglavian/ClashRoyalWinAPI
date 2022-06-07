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

//void Rendering::buffering(HWND p_hwnd) {
//	h_dc = GetDC(p_hwnd);
//	h_memdc = CreateCompatibleDC(h_dc);
//	h_imgdc = CreateCompatibleDC(h_dc);
//	//if (h_bufbit == nullptr) {
//	//	h_bufbit = CreateCompatibleBitmap(h_dc, window.right, window.bottom);
//	//}
//	//FillRect(h_memdc, &window, GetSysColorBrush(COLOR_WINDOW));
//
//	//h_oldbit = (HBITMAP)SelectObject(h_memdc, h_bit);
//	//GetObject(h_bit, sizeof(BITMAP), &bit);
//	//StretchBlt(h_dc, 10, 10, bit.bmWidth / 3, bit.bmHeight / 3, h_memdc, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);
//	//
//	//SelectObject(h_memdc, h_oldbit);
//	//DeleteObject(h_bit);
//
//	DeleteDC(h_imgdc);
//	DeleteDC(h_memdc);
//	ReleaseDC(p_hwnd, h_dc);
//	InvalidateRect(p_hwnd, NULL, FALSE);
//}
//
//void Rendering::draw_bitmap(HWND p_hwnd, int p_x, int p_y) {
//	if (h_bufbit == nullptr) return;
//	h_dc = BeginPaint(p_hwnd, ps);
//	h_memdc = CreateCompatibleDC(h_dc);
//	h_oldbit = (HBITMAP)SelectObject(h_memdc, h_bufbit);
//	GetObject(h_bufbit, sizeof(BITMAP), bit);
//	BitBlt(h_dc, p_x, p_y, bit->bmWidth, bit->bmHeight, h_memdc, 0, 0, SRCCOPY);
//	SelectObject(h_memdc, h_oldbit);
//	DeleteDC(h_memdc);	
//	EndPaint(p_hwnd, ps);
//} 