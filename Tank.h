#pragma once

class Field;

class Tank
{
private:
  int id_ = 0, hp_ = 0;
  double x_ = 0, y_ = 0, angle_ = 0;
public:
  Tank();
  Tank(double x, double y, double angle);
  Tank(int id_, double x_, double y_, int hp_, double angle_);
  ~Tank();
  void setId(int x);
  int getId();
  void forward(double x);
  void shoot(double dist, Field& field);
  void turn(double x);
  void damage();
  double my_x();
  double my_y();
  int my_hp();
  double enemy_x(Field& field);
  double enemy_y(Field& field);

};
