#include "Tank.h"
#include "Field.h"
#include <cmath>
#include <thread>


Tank::Tank() = default;
Tank::Tank(double x, double y, double angle) {
    id_ = 0;
    x_ = x;
    y_ = y;
    hp_ = 100;
    angle_ = angle;
    if (x_ < LEFT + 50) x_ = LEFT + 50;
    if (y_ < TOP + 50) y_ = TOP + 50;
    if (x_ > RIGHT - 50) x_ = RIGHT - 50;
    if (y_ > BOTTOM - 50) y_ = BOTTOM - 50;
}

//Дать танку ID
void  Tank::setId(int x) {
    id_ = x;
}

//Получить ID танка
int  Tank::getId() { return id_; }
  
//Сдвинуться на dist пикселей (назад если dist < 0)
void Tank::forward(double dist) {
    int sign = 1;
    if (dist < 0) {
        dist = -dist;
        sign = -1;
    }
    for (int i = 0; i < dist; i++) {
        x_ += cos(angle_ * 3.14 / 180) * sign;
        y_ += sin(angle_ * 3.14 / 180) * sign;
        if (x_ < LEFT + 50) x_ = LEFT + 50;
        if (y_ < TOP + 50) y_ = TOP + 50;
        if (x_ > RIGHT - 50) x_ = RIGHT - 50;
        if (y_ > BOTTOM - 50) y_ = BOTTOM - 50;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}

//Выстрелить в направлении angle_
void  Tank::shoot(double dist, Field& field) {    
    if (hp_ <= 0) {
        return;
    }
    //Создаем снаряд в поле
    field.createProjectile(x_ + 50 * cos(angle_ * 3.14 / 180), y_ + 50 * sin(angle_ * 3.14 / 180), angle_, dist, id_);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

double Tank::getAngle() {
    return angle_;
}

void  Tank::turn(double x) {
    int sign = 1;
    if (x < 0) {
        x = -x;
        sign = -1;
    }
    for (int i = 0; i < x; i++) {
        angle_ += sign;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void  Tank::damage() {
    hp_ -= 50;
}

//Получение данных членов класса
double  Tank::my_x() { return x_; }
double  Tank::my_y() { return y_; }
int  Tank::my_hp() {return hp_; }

//Получение данных врага
double  Tank::enemy_x(Field& field) {
    for (Tank* other : field.getTanks()) {
        if (other->getId() != id_) {
            return other->my_x();
        }
    }
    return 0;
};
double  Tank::enemy_y(Field& field) {
    for (Tank* other : field.getTanks()) {
        if (other->getId() != id_) {
            return other->my_y();
        }
    }
    return 0;
};

Tank::~Tank() = default;

Tank::Tank(int id_, double x_, double y_, int hp_, double angle_)
      : id_(id_), x_(x_), y_(y_), hp_(hp_), angle_(angle_) {}
