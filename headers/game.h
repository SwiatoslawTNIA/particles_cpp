#ifndef GAME_
#define GAME_
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
class Game
{
  private:
  
  sf::RenderWindow window;
  sf::CircleShape particle;
  //keys:
  bool is_moving_up{false},
       is_moving_down{false},
       is_moving_left{false},
       is_moving_right{false};
  void processEvents();
  void update();
  void render();
  void handlePlayerInput(sf::Keyboard::Key key, bool key_pressed);

  void display_exit();
  public:
    Game();
    void run();

};
#endif
