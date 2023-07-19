#pragma once

class Projectile
{
private:
  double x_, y_, angle_, dist_, traveled_;
public:
  Projectile(double x, double y, double angle, double dist);
  void move();
  double my_x();
  double my_y();
  bool isOut();
  ~Projectile();
};

