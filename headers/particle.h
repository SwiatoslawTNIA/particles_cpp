#ifndef PARTICLE_
#define PARTICLE_
#include <tuple>
#include <SFML/Graphics.hpp>
//each particle has different size, 
class Particle
{
private:
  int x_;
  int y_;
  float x_vel_;
  float y_vel_;
  float size_;
public:
  Particle(int x, int y, float x_vel, float y_vel, float size):x_{x}, y_{y},  x_vel_{x_vel}, y_vel_{y_vel},size_{size}{}
  Particle(const Particle&);
  Particle& operator=(const Particle&);
  //no moving:
  Particle(Particle &&) = delete;
  Particle& operator=(Particle &&) = delete;

  //methods:

  //getters, setters:
  std::pair<int,int> get_coords(void) const noexcept {return std::pair<int,int>{x_, y_};}
  double get_size(void) const noexcept{return this->size_;}
  std::pair<float,float> get_vel(void) const noexcept{return std::pair<float,float>{x_vel_, y_vel_};}
};
#endif