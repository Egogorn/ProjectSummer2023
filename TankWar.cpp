#include <thread>
#include <chrono>
#include <vector>
#include "Field.h"
#include "graphics.h"
#include <iostream>

std::vector<Tank*> tanks;
Field field;

//Программа движения танка1
void Tank1(Tank* tank) {
	tank->forward(10);
	tank->shoot(5, field);
}


//Программа движения танка2
void Tank2(Tank* tank) {
	tank->turn(90);
	tank->forward(20);
	tank->shoot(5, field);
}

void init() {
	Tank* tank1 = new Tank(50, 50, 0);
	Tank* tank2 = new Tank(50, 100, 180);
	tanks.push_back(tank1);
	tanks.push_back(tank2);
	field = Field(tanks);
	std::thread th1(Tank1, tanks[0]);
	std::thread th2(Tank2, tanks[1]);
	th1.detach();
	th2.detach();
}


int main() {
	init();

}