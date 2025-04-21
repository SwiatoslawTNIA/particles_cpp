#ifndef SHOT_
#define SHOT_
#include <tuple>
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

class Shot
{
private:
  sf::Sprite shape_;
public:
  Shot(sf::Texture& texture);
  sf::Sprite& get_shape(void) {return shape_;}

};
#endif