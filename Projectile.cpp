#include "Projectile.h"
#include <cmath>


Projectile::Projectile(double x, double y, double angle, double dist) {
    x_ = x;
    y_ = y;
    angle_ = angle;
    dist_ = dist;
    traveled_ = 0;
  };

  double Projectile::my_x() {return x_ ;}
  double Projectile::my_y() {return y_ ;}

  bool Projectile::isOut() {
    return dist_ < traveled_;
  };

  void Projectile::move() {
    x_ += cos(angle_ * 3.14 / 180);
    y_ += sin(angle_ * 3.14 / 180);
    traveled_ += 1;
  }

  Projectile::~Projectile() = default;

