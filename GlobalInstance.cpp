//#include "GlobalInstance.h"
//
//GInstance::GInstance(HINSTANCE p_hinst, HWND p_hwnd) {
//	hInst = p_hinst;
//	hWndMain = p_hwnd;
//}
//
//GInstance& GInstance::get_instance(HINSTANCE p_hinst, HWND p_hwnd) {
//	static GInstance* instance = new GInstance(p_hinst, p_hwnd);
//	return *instance;
//}
//
//HINSTANCE& GInstance::get_hinst() {
//	return hInst;
//}
//
//GInstance::~GInstance() { }
