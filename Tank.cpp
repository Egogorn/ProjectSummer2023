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
  }
  void  Tank::setId(int x) {
    id_ = x;
  }
  int  Tank::getId() { return id_; }
  void Tank::forward(double dist) {
    for (int i = 0; i < dist; i++) {
      x_ += cos(angle_ * 3.14 / 180);
      y_ += sin(angle_ * 3.14 / 180);
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  }
  void  Tank::shoot(double dist, Field& field) {
    field.createProjectile(x_, y_, angle_, dist);
  };
  void  Tank::turn(double x) {
    for (int i = 0; i < x; i++) {
      angle_ += 1;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  };
  void  Tank::damage() {
    hp_ -= 50;
  }
  double  Tank::my_x() { return x_; }
  double  Tank::my_y() { return y_; }
  int  Tank::my_hp() {return hp_; }
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
      : id_(id_), x_(x_), y_(y_), hp_(hp_), angle_(angle_)
  {
  }
