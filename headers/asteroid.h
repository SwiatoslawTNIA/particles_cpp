#ifndef ASTEROID_
#define ASTEROID_
/*
Each asteroid randomly appears and becomes visible from the very start, so we need to set it's position properly before updating it
2.probably will need to store the scale option, since I want for different asteroids to have different 
*/
#include <SFML/Graphics.hpp>
#include <random>

class Asteroid
{
    private:
        sf::Sprite shape_;
        float scale_;//to store the custom scaling, to be able to detect collisions
        static float scale(void) noexcept
        {
            std::random_device rd;//seed 
        }
    public:
    Asteroid(sf::Texture& texture)
    {
        shape_.setTexture(texture);
        

    }
};


#endif 