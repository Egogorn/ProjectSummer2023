#include "Tank.h"
#include "Field.h"
#include <cmath>
#include <thread>

Field field;

class Tank
{
private:
  int id_;
  double x_, y_, hp_, angle_;
public:
  Tank();
  Tank(double x, double y, double angle) {
    id_ = 0;
    x_ = x;
    y_ = y;
    hp_ = 100;
    angle_ = angle;
  }
  ~Tank();
  void setId(int x) {
    id_ = x;
  }
  int getId() { return id_; }
  void forward(double dist) {
    for (int i = 0; i < dist; i++) {
      x_ += cos(angle_ * 3.14 / 180);
      y_ += sin(angle_ * 3.14 / 180);
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  }
  void shoot(double dist) {
    field.createProjectile(x_, y_, angle_, dist);
  };
  void turn(double x) {
    for (int i = 0; i < x; i++) {
      angle_ += 1;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  };
  void damage() {
    hp_ -= 50;
  }
  double my_x() { return x_; }
  double my_y() { return y_; }
  int my_hp() {return hp_; }
  int enemy_x() {
    for (Tank other : field.getTanks()) {
      if (other.getId() != id_) {
        return other.my_x();
      }
    }
  };
  int enemy_y() {
    for (Tank other : field.getTanks()) {
      if (other.getId() != id_) {
        return other.my_y();
      }
    }
  };
};