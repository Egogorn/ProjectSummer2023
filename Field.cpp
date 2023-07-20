#include "Field.h"
#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>

std::mutex proj_mutex;

Field::Field() = default;

Field::Field(std::vector<Tank*> tanks) : tanks_(tanks) {
    for (int i = 0; i < tanks_.size(); i++) {
        tanks_[i]->setId(i + 1);
    }
    projectiles_ = std::vector<Projectile*>();
};

//Получение вектора танков
std::vector<Tank*> Field::getTanks() {
    return tanks_;
}
//Создание снаряда в поле
void Field::createProjectile(double x, double y, double angle, double dist, int id) {
    std::lock_guard<std::mutex> lock(proj_mutex);
    Projectile* proj = new Projectile(x,y,angle,dist, id);
    projectiles_.push_back(proj);
}
//Удаление снаряда из поля
void Field::removeProjectile(int i) {
    free(projectiles_[i]);
    projectiles_.erase(projectiles_.begin() + i);
}
//Произвести перемещение всех снарядов и проверить столкновения.
void Field::moveProjectiles() {
    while (true) {
        int i = 0;
        while (i < projectiles_.size()) {
            projectiles_[i]->move();
            if (projectiles_[i]->isOut()) {
                removeProjectile(i);
                continue;
            }
            for (int j = 0; j < tanks_.size(); j++) {
                if (tanks_[j]->getId() != projectiles_[i]->getId()) {
                    if ((tanks_[j]->my_x() - projectiles_[i]->my_x()) * (tanks_[j]->my_x() - projectiles_[i]->my_x()) + (tanks_[j]->my_y() - projectiles_[i]->my_y()) * (tanks_[j]->my_y() - projectiles_[i]->my_y()) < 2500) {
                        removeProjectile(i);
                        i--;
                        tanks_[j]->damage();
                        if (tanks_[j]->my_hp() <= 0) {
                            tanks_.erase(tanks_.begin() + j);
                            continue;
                        }
                        if (i < 0) {
                            break;
                        }
                    }
                }
            }
        i++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

//Получение вектора снарядов
    std::vector<Projectile*> Field::getProjectiles() {
        return projectiles_;
    }

