#include "Projectile.h"
#include <cmath>


Projectile::Projectile(double x, double y, double angle, double dist, int id) {
    x_ = x;
    y_ = y;
    id_ = id;
    angle_ = angle;
    dist_ = dist;
    traveled_ = 0;
  };

  double Projectile::my_x() {return x_ ;}
  double Projectile::my_y() {return y_ ;}

  //Проверка на максимальное расстояние
  bool Projectile::isOut() {
    return dist_ < traveled_;
  };

  //Сдвинуть снаряд на 1 пиксель
  void Projectile::move() {
    x_ += cos(angle_ * 3.14 / 180);
    y_ += sin(angle_ * 3.14 / 180);
    traveled_ += 1;
  }

  //Получение ID снаряда
  int Projectile::getId() {
      return id_;
  }

  Projectile::~Projectile() = default;

