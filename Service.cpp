#include "Service.h"

Service::Service() {
	rend_tick = new Tick(200);
	bar = new Barbarian(3, 4);
	arch = new Archer(2, 3);
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

