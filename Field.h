#pragma once
#include "Projectile.h"
#include "Tank.h"
#include <vector>

class Field {
  private:
    std::vector<Tank*> tanks_ = std::vector<Tank*>(0, nullptr);
    std::vector<Projectile> projectiles_;
  public:
    Field();

    Field(std::vector<Tank*> tanks);
    
    std::vector<Tank*> getTanks();

    void createProjectile(double x, double y, double angle, double dist);
    
    void removeProjectile(int i);

    void moveProjectiles();
};