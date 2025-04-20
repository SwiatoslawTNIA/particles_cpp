//---------------------------------------------------------------------------------------------------------------------
// main.cc
//
// main file, connects main logic
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "main.h"

//---------------------------------------------------------------------------------------------------------------------
///
/// This is an example header comment. Here, you explain, what the
/// function does. Copypaste and adapt it!
///
/// @param numbers an array to check
/// @param length The length of the array. If this text is too long you can
///
/// @return the highest number
//
int main(void)
{
  // int particle_n{init()};
  std::vector<Particle> particles;
  
  
  //create the window:
  // sf::RenderWindow window(sf::VideoMode(800, 600), "Particles");
  // // sf::Text t{"Hello, welcome to the particle simulation"}
  // sf::CircleShape circle(100.f);
  // circle.setFillColor(sf::Color::Green);

  // while(window.isOpen())
  // {
  //   sf::Event event;
  //   while(window.pollEvent(event))
  //   {
  //     //close the window on exit:
  //     if(event.type == sf::Event::Closed)
  //       window.close();


  //     window.clear();

  //     window.draw(circle);
  //     window.display();
  //   }
  // }
  Game game;
  game.run();
  return 0;
}

