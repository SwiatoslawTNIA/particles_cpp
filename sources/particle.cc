#include "particle.h"

//copy constructor:
Particle::Particle(const Particle& p):x_{p.x_}, y_{p.y_}, x_vel_{p.x_vel_}, y_vel_{p.y_vel_}, size_{p.size_}{}


//assignment operator:
Particle& Particle::operator=(const Particle& p)
{
  if(this == &p)
    return *this;
  x_ = p.x_;
  y_ = p.y_;
  x_vel_ = p.x_vel_;
  y_vel_ = p.y_vel_;
  size_ = p.size_;
}