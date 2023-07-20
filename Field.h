#pragma once
#include "Projectile.h"
#include "Tank.h"
#include <vector>
#include <mutex>


class Field {
  private:
    std::vector<Tank*> tanks_ = std::vector<Tank*>(0, nullptr);
    std::vector<Projectile*> projectiles_ = std::vector<Projectile*>(0, nullptr);
  public:
    Field();

    Field(std::vector<Tank*> tanks);
    
    std::vector<Tank*> getTanks();

    void createProjectile(double x, double y, double angle, double dist, int id);
    
    void removeProjectile(int i);

    void moveProjectiles();

    std::vector<Projectile*> getProjectiles();
};