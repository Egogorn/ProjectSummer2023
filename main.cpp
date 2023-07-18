#include <thread>
#include <chrono>
#include <vector>
#include "Field.h"
#include "graphics.h"

std::vector<Tank&> tanks;
Field field(tanks);

//Программа движения танка1
void Tank1(Tank& tank) {
  tank.forward(10);
  tank.shoot(5);
}


//Программа движения танка2
void Tank2(Tank& tank) {
  tank.turn(90);
  tank.forward(20);
  tank.shoot(5);
}

void init() {
  Tank tank1(50, 50, 0);
  Tank tank2(50, 100, 180);
  tanks.push_back(tank1);
  tanks.push_back(tank2);
  std::thread(Tank1, tanks[0]);
  std::thread(Tank2, tanks[1]);
}


int main () {
  init();

}