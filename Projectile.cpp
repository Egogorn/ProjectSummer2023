#include "Projectile.h"
#include <cmath>

class Projectile
{
private:
  double x_, y_, angle_, dist_, traveled_;
public:
  Projectile(double x, double y, double angle, double dist) {
    x_ = x;
    y_ = y;
    angle_ = angle;
    dist_ = dist;
    traveled_ = 0;
  };

  double my_x() {return x_ ;}
  double my_y() {return y_ ;}

  bool isOut() {
    return dist_ < traveled_;
  };

  void move() {
    x_ += cos(angle_ * 3.14 / 180);
    y_ += sin(angle_ * 3.14 / 180);
    traveled_ += 1;
  }

  ~Projectile();
};

