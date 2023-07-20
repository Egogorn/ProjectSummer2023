#include <thread>
#include <chrono>
#include <vector>
#include "Field.h"
#include "graphics.h"
#include <iostream>
#pragma comment(lib, "Msimg32.lib")

//Глобальные переменные для доступа к ним внутри функций
std::vector<Tank*> tanks; // Хранит указатели на танки
Field field; // Поле наблюдает(содержит) за всеми танками и снарядами

/*
forward(x) - сдвинуться на x (если x < 0, то движение назад)
shoot(x, field) - выстрелить снарядом который пролетит пока не попадет в другой танк, или пролетит x пикселей. field - поле, в котором находятся танки.
turn(x) - повернуть на x градусов (x > 0 - по часовой, x < 0 - против часовой)
my_x() - узнать свой x
my_y() - узнать свой y
enemy_x() - узнать координату x врага
enemy_y() - узнать координату y врага
*/

/*
Для увеличение кол-ва танков нужно написать
новую функцию void TankN(Tank* tank) и
вызвать её в отдельном потоке внутри init()
*/


//Программа действий танка 1
void Tank1(Tank* tank) {
	tank->shoot(250, field);
	tank->shoot(200, field);
	tank->shoot(300, field);
	tank->shoot(200, field);
	tank->shoot(200, field);
}


//Программа действий танка 2
void Tank2(Tank* tank) {
	tank->shoot(50, field);
	tank->shoot(150, field);
	tank->shoot(200, field);
	tank->shoot(200, field);
	tank->shoot(200, field);
}

void init() {
	Tank* tank1 = new Tank(250, 0, 90);
	Tank* tank2 = new Tank(250, 250, -90);
	tanks.push_back(tank1);
	tanks.push_back(tank2);
	field = Field(tanks);
	//Распараллеливаем расчеты действий танков, движения снарядов.
	std::thread th1(Tank1, tanks[0]);
	std::thread th2(Tank2, tanks[1]);
	std::thread th3(&Field::moveProjectiles, &field);
	//Не ожидаем окончания потоков
	th1.detach();
	th2.detach();
	th3.detach();
}


int main() {
	initwindow(WX, WY, "Танки", 0, 0, true); // режим 2-страниц
	// видима страница 0, активна страница 1
	init();
	while (1)
	{
		//Установка цвета фона
		setbkcolor(GREEN);
		clearviewport();
		//Рисование стены
		rectangle(50, 50, 750, 750);
		//Получаем вектор снарядов и отрисовываем их
		std::vector<Projectile*> proj = field.getProjectiles();
		for (int i = 0; i < proj.size(); i++) {
			circle(proj[i]->my_x(), proj[i]->my_y(), 10);
		}
		//Отрисовываем танки
		tanks = field.getTanks();
		for (int i = 0; i < tanks.size(); i++) {
			if (i == 0) {
				setfillstyle(HATCH_FILL, RED);
				setcolor(RED);
			}
			else {
				setfillstyle(SLASH_FILL, BLUE);
				setcolor(BLUE);
			}
			int a[4] = { tanks[i]->my_x(), tanks[i]->my_y(), tanks[i]->my_x() + 70 * cos(tanks[i]->getAngle() * 3.14 / 180), tanks[i]->my_y() + 70 * sin(tanks[i]->getAngle() * 3.14 / 180) };
			fillellipse(tanks[i]->my_x(), tanks[i]->my_y(), 50, 50);
			fillpoly(2, a);
		}
		//Меняем кадр
		swapbuffers();
		if (kbhit()) break;
	}
	closegraph();
}