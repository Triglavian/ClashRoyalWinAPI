#pragma once
#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain, h_card1, h_card2;
LPCTSTR lpszClass = TEXT("ä�ؿ�_21311023");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance , LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

HBITMAP g_membit;
POINT g_btpos[2];	//each card button pos

void render(HWND, WPARAM, LPARAM);
#define CARD_ARCH 101
#define CARD_BARB 102
void draw_bitmap(HDC, int, int, HBITMAP);

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC h_dc, h_memdc;
	PAINTSTRUCT ps;
	HBITMAP h_bit, h_oldbit;
	BITMAP bit;
	POINT cursor;
	switch (iMessage) {
		case WM_CREATE:
			//archer card
			h_bit = (HBITMAP)LoadImage(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, NULL, NULL, LR_DEFAULTCOLOR);
			GetObject(h_bit, sizeof(BITMAP), &bit);
			g_btpos[0] = { 500, 500};
			h_card1 = CreateWindow(L"button", L"", WS_CHILD | WS_VISIBLE | BS_BITMAP, g_btpos[0].x, g_btpos[0].y, bit.bmWidth, bit.bmHeight, hWnd, (HMENU)CARD_ARCH, g_hInst, nullptr);
			SendMessage(h_card1, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)h_bit);
			//barbarian card
			h_bit = (HBITMAP)LoadImage(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, NULL, NULL, LR_DEFAULTCOLOR);
			g_btpos[1] = { g_btpos[0].x + bit.bmWidth + 20, g_btpos[0].y};
			h_card2 = CreateWindow(L"button", L"", WS_CHILD | WS_VISIBLE | BS_BITMAP, g_btpos[1].x, g_btpos[1].y,bit.bmWidth, bit.bmHeight, hWnd, (HMENU)CARD_BARB, g_hInst, nullptr);
			SendMessage(h_card2, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)h_bit);

			SetTimer(hWnd, 1, 33, nullptr);
			return 0;
		case WM_TIMER:
			render(hWnd, wParam, lParam);
			return 0;
		case WM_LBUTTONDOWN:
			
			return 0;
		case WM_PAINT:
			h_dc = BeginPaint(hWnd, &ps);
			h_memdc = CreateCompatibleDC(h_dc);

			if (g_membit != nullptr) draw_bitmap(h_dc, 0, 0, g_membit);
			EndPaint(hWnd, &ps);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void render(HWND p_hwnd, WPARAM p_wparam, LPARAM p_lparam) {
	HDC h_dc, h_memdc, h_imgdc;
	HBITMAP h_bit, h_oldbit, h_gbit;
	BITMAP bit;
	RECT window;
	h_dc = GetDC(p_hwnd);
	h_memdc = CreateCompatibleDC(h_dc);
	h_imgdc	= CreateCompatibleDC(h_dc);
	GetClientRect(p_hwnd, &window);
	if (g_membit == nullptr) {
		g_membit = CreateCompatibleBitmap(h_dc, window.right, window.bottom);
	}
	h_gbit = (HBITMAP)SelectObject(h_memdc, g_membit);
	FillRect(h_memdc, &window, (HBRUSH)GetSysColor(WHITE_BRUSH));
	
	Rectangle(h_memdc, window.left + 50, window.top + 50, window.right - 50, 450);

	

	DeleteDC(h_imgdc);	
	SelectObject(h_memdc, h_gbit);
	DeleteDC(h_memdc);
	ReleaseDC(p_hwnd, h_dc);
	InvalidateRect(p_hwnd, nullptr, false);
}

void draw_bitmap(HDC p_dc, int p_x, int p_y, HBITMAP p_hbitmap) {
	HDC h_memdc; 
	HBITMAP h_oldbit;
	BITMAP bit;
	h_memdc = CreateCompatibleDC(p_dc);
	h_oldbit = (HBITMAP)SelectObject(h_memdc, p_hbitmap);
	GetObject(p_hbitmap, sizeof(BITMAP), &bit);
	BitBlt(p_dc, 0, 0, bit.bmWidth, bit.bmHeight, h_memdc, 0, 0, SRCCOPY);
	SelectObject(h_memdc, h_oldbit);
	DeleteDC(h_memdc);
}