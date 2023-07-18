#include "Projectile.h"
#include "Tank.h"
#include <vector>

class Field {
  private:
    std::vector<Tank&> tanks_;
    std::vector<Projectile> projectiles_;
  public:
    Field();

    Field(std::vector<Tank&> tanks);
    
    std::vector<Tank&> getTanks() {
      return tanks_;
    }

    void createProjectile(double x, double y, double angle, double dist);
    
    void moveProjectiles();
};