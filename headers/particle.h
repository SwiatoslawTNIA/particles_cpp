#ifndef PARTICLE_
#define PARTICLE_

//each particle has different size, color, 
class Particle
{
private:
  enum class color{RED, BLUE, GREEN, YELLOW};

  int x_coord_;
  int y_coord_;
  double size_;
  double velocity_;
public:
  Particle(int x_coord, int y_coord, double size, double velocity):x_coord_{x_coord}, y_coord_{y_coord}, size_{size}, velocity_{velocity}{}
};
#endif