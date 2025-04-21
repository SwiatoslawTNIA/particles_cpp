#ifndef GAME_
#define GAME_



#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <iostream>

#include "shot.h"
#include "asteroid.h"

#define PLANE_PATH "images/plane2.png"
#define BULLET_PATH "images/projectile.png"
#define ASTEROID_PATH "images/asteroid.png"

#define SHOT_DELAY 500 

class Game
{
  private:
  
  sf::RenderWindow window;

  //resources:
  sf::Sprite player;
  std::vector<Shot> shots;
  
  //textures:
  sf::Texture texture;
  sf::Texture bullet_texture;
  sf::Texture asteroid;

  //keys:
  bool is_moving_up{false},
       is_moving_down{false},
       is_moving_left{false},
       is_moving_right{false};
      
  //delay for shots
  std::chrono::system_clock::time_point time;
  //methods:

  void processEvents();
  void update(sf::Time delta_time);
  void render();
  void handlePlayerInput(sf::Keyboard::Key key, bool key_pressed);
  public:
    Game();
    void run();

};

#endif
