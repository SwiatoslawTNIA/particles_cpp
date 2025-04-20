#include "game.h"
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief game defualt constructor
///
/// @param void 
///
/// @return void
//
Game::Game(void):
window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Particles"), particle()
{
  particle.setRadius(40.f);
  particle.setPosition(100.f, 100.f);
  particle.setFillColor(sf::Color::Cyan);
}
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief loops evenly producing frames
///
/// @param void 
///
/// @return void
//
void Game::run()
{
  while(window.isOpen())
  {
    processEvents();//user input, closes the window if sf::Event::Closed
    update();
    render();
  }
}
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief reacts to different events created by the user
///
/// @param void 
///
/// @return void
// 
void Game::processEvents()
{
  sf::Event event;
  while(window.pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::KeyPressed:
      handlePlayerInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      handlePlayerInput(event.key.code, false);
      break;
    case sf::Event::Closed:
      window.close();
      break;
    default:
      break;
    }
  }
}
/*
------>x 
|
|
|
y
*/
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief update the game logic
///
/// @param void 
///
/// @return void
//
void Game::update(void) 
{
  sf::Vector2f movement(0.f, 0.f);
  if(is_moving_down)
    movement.y -= 1.f;//abbreviated from 1.0f
  if(is_moving_left)
    movement.x -= 1.f;
  if(is_moving_right)
    movement.x += 1.f;
  if(is_moving_up)
    movement.y += 1.f;
  particle.move(movement);
}
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief render the game to the screen
///
/// @param void 
///
/// @return void
//
void Game::render(void)
{
  window.clear();
  window.draw(particle);
  window.display();
}
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief handles the keypresses by redistributing them among the bools, so that the update func can properly respond 
/// to the keys pressed
///
/// @param key key pressed
/// @param is_pressed determines if the key has been pressed/released
///
/// @return return
//
void Game::handlePlayerInput(sf::Keyboard::Key key, bool is_pressed)
{
  if(key == sf::Keyboard::W)
    is_moving_up = is_pressed;
  else if(key == sf::Keyboard::A)
    is_moving_left = is_pressed;
  else if(key == sf::Keyboard::D)
    is_moving_right = is_pressed;
  else if(key == sf::Keyboard::S)
    is_moving_down = is_pressed;
}
void Game::display_exit()
{
  sf::Text text;
  int text_size{40};
  // text.setString("Bye, have a nice time!");
  text.setCharacterSize(text_size);

  std::pair<float, float> coords {
    sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height
  };//[x,y]
  // text.setPosition( (coords.first - text.getString().getSize()) / 2, (coords.second - text_size) / 2);
  // auto now = std::chrono::system_clock::now();

  // while(window.isOpen())
  // {
  //   if(std::chrono::system_clock::now() > now + std::chrono::seconds(3))
  //     window.close();
  // }
}