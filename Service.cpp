#include "Service.h"

Service::Service() {
	//rend_tick = new Tick();
	//bar = new Barbarian({ 200, 200 });
	//arch = new Archer({ 300, 300 });
}

Service::~Service() { 
	delete rend_tick;
	delete bar;
	delete arch;
}

void Service::run() {
	while (1) {
		calculation();
		if (rend_tick->is_tick() == true) {
			rendering();
		}
	}
}

void Service::calculation() {

}

void Service::rendering() {

}

