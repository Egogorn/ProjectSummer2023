#pragma once

class Projectile
{
private:
  double x_, y_, angle_, dist_, traveled_;
  int id_;
public:
  Projectile(double x, double y, double angle, double dist, int id);
  void move();
  int getId();
  double my_x();
  double my_y();
  bool isOut();
  ~Projectile();
};

