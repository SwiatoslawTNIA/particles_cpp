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
window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Particles"), particle{}
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
  //to measure the time each frame takes to load, delta_time must always be the same!!!
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while(window.isOpen())
  {
    processEvents();//user input, closes the window if sf::Event::Closed
    timeSinceLastUpdate += clock.restart();
    sf::Time delta_time = clock.restart();//returns the elapsed time since its start + restarts the clock
    update(delta_time);
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
/// @param delta_time carries the time elapsed from the last frame, can be converted to seconds to move the object properly
/// independent of current frame rate
///
/// @return void
//
void Game::update(sf::Time delta_time) 
{
  sf::Vector2f movement(0.f, 0.f);
  float speed{50.f};

  //check if the particle is out_of_bounds:
  auto particle_bounds = particle.getGlobalBounds();
  auto window_size = window.getSize();

  if(is_moving_down && ( particle_bounds.top + particle_bounds.height + speed <= window_size.y))
    movement.y += speed;//abbreviated from 1.0f
  if(is_moving_left  && (particle_bounds.left - speed >= 0))
    movement.x -= speed;
  if(is_moving_right  && ( particle_bounds.left + particle_bounds.width + speed <= window_size.x))
    movement.x += speed;
  if(is_moving_up  && ( particle_bounds.top - speed >= 0))
    movement.y -= speed;
  particle.move(movement * delta_time.asSeconds());

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
//each key is both pressed and unpressed, which triggers the event, on unpressed each is_moving_... gets set to false
//because of the 
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
  else if(key == sf::Keyboard::Q)
    window.close();
}
