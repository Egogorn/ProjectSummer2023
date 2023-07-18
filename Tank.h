class Tank
{
private:
  int id_;
  double x_, y_, hp_, angle_;
public:
  Tank();
  Tank(double x, double y, double angle) {}
  ~Tank();
  void setId(int x) {};
  void forward(int x);
  void shoot(int dist);
  void turn(int x);
  void damage();
  int my_x();
  int my_y();
  int my_hp();
  int enemy_x();
  int enemy_y();
};
