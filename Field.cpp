#include "Field.h"
#include <thread>
#include <chrono>
#include <cmath>

class Field {
  private:
    std::vector<Tank&> tanks_;
    std::vector<Projectile> projectiles_;
  public:
    Field() = default;

    Field(std::vector<Tank&> tanks) : tanks_(tanks), projectiles_() {
      for (int i = 0; i < tanks.size(); i++) {
        tanks[i].setId(i + 1);
      }
    };

    std::vector<Tank&> getTanks() {
      return tanks_;
    }
    
    void createProjectile(double x, double y, double angle, double dist) {
      Projectile proj(x,y,angle,dist);
      projectiles_.push_back(proj);
    }

    void removeProjectile(int i) {
      projectiles_.erase(projectiles_.begin() + i);
    }
    
    void moveProjectiles() {
      for (int i = 0; i < projectiles_.size(); i++) {
        projectiles_[i].move();
        if (projectiles_[i].isOut()) {
          removeProjectile(i);
          i--;
        }
        for (int j = 0; j < 2; i++) {
          if ((tanks_[j].my_x() - projectiles_[i].my_x()) * (tanks_[j].my_x() - projectiles_[i].my_x()) + (tanks_[j].my_y() - projectiles_[i].my_y()) * (tanks_[j].my_y() - projectiles_[i].my_y()) <= 100) {
            removeProjectile(i);
            i--;
            tanks_[j].damage();
            if (tanks_[j].my_hp() <= 0) {
              tanks_.erase(tanks_.begin() + j);
            }
          }
        }
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
};
