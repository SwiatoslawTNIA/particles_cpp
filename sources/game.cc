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
window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "the most BADASS shooter ever"), player{}
{
  //enable v-sync:
  window.setVerticalSyncEnabled(true);
  //hide mouse-cursor:
  window.setMouseCursorVisible(false);

  //loading the aircraft:
  if(!texture.loadFromFile(PLANE_PATH))
  {
    std::cerr << "Unable to locate the plane image, exiting...";
    exit(EXIT_FAILURE);
  }
  if(!bullet_texture.loadFromFile(BULLET_PATH))
  {
    std::cerr << "Unable to locate the bullet image, exiting...";
    exit(EXIT_FAILURE);
  }
  if(!asteroid.loadFromFile(ASTEROID_PATH))
  {
    std::cerr << "Unable to locate the asteroid image, exiting...";
    exit(EXIT_FAILURE);
  }
  //init the player:
  player.setScale(0.3f, 0.3f);
  player.setTexture(texture);
  player.setPosition(100.f, 100.f);

  //shot's delay:
  time = std::chrono::system_clock::now() - std::chrono::milliseconds(SHOT_DELAY);//we can start shooting immediately
}
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief loops evenly producing frames
///
/// @param void 
///
/// @return void
//
void Game::run(void)
{ 
  const sf::Time time_per_frame{sf::seconds(1.f / 120.f)};//120 fps
  //to measure the time each frame takes to load, delta_time must always be the same!!!
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while(window.isOpen())
  {
    processEvents();//user input, closes the window if sf::Event::Closed
    timeSinceLastUpdate += clock.restart();
    while(timeSinceLastUpdate > time_per_frame)//time since last state update > time required for one frame
    {
      timeSinceLastUpdate -= time_per_frame;
      processEvents();
      update(time_per_frame);
    }
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
  float speed{600.f};

  //check if the player is out_of_bounds:
  auto player_bounds = player.getGlobalBounds();
  auto window_size = window.getSize();

  if(is_moving_down && (player_bounds.top + player_bounds.height + speed * delta_time.asSeconds()<= window_size.y))
    movement.y += speed;//abbreviated from 1.0f
  if(is_moving_left  && (player_bounds.left - speed * delta_time.asSeconds() >= 0))
    movement.x -= speed;
  if(is_moving_right  && (player_bounds.left + player_bounds.width + speed * delta_time.asSeconds() <= window_size.x))
    movement.x += speed;
  if(is_moving_up  && (player_bounds.top - speed * delta_time.asSeconds() >= 0))
    movement.y -= speed;
  player.move(movement * delta_time.asSeconds());

  //update the shots:
  float shot_speed{800.f};
  for(std::size_t i = 0; i < shots.size(); ++i)
  {
    auto shot_bounds = shots[i].get_shape().getGlobalBounds();

    shots[i].get_shape().move(sf::Vector2f{0.f, - shot_speed * delta_time.asSeconds()});

    if(shot_bounds.top + shot_bounds.height < 0)
      shots.erase(shots.begin() + i--);//erase the shot, update the i index

  }
}
//---------------------------------------------------------------------------------------------------------------------
/*

  sf::Texture class holds the actual image data (loaded from memory)
  sf::Sprite class represents an instance with position and orientation in the scene(where and how to put an image
  on the screen)
*/
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
  window.clear(sf::Color::Black);
  window.draw(player);

  //render shots:
  for(std::size_t i = 0; i < shots.size(); ++i)
    window.draw(shots[i].get_shape());
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
  else if(key == sf::Keyboard::F && is_pressed && std::chrono::system_clock::now() - time >= std::chrono::milliseconds(SHOT_DELAY))
  //introducing a half a second delay
  {
    Shot shot{bullet_texture};
    //set position:
    sf::FloatRect player_bounds = player.getGlobalBounds();
    sf::FloatRect shot_bounds = shot.get_shape().getGlobalBounds();

    shot.get_shape().setPosition
    (player_bounds.left + (player_bounds.width  - shot_bounds.width) / 2, player_bounds.top - shot_bounds.height);
    shots.push_back(shot);//store the shot in the shots vector
    time = std::chrono::system_clock::now();//reset the shot's timer
  }
  else if(key == sf::Keyboard::Q)
    window.close();
}

