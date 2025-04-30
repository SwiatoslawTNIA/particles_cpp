#include "shot.h"
//---------------------------------------------------------------------------------------------------------------------
///
/// \brief encampsulates each shot as a whole
///
/// @param texture the texture loaded from game, to implement to each bullet
///
/// @return void
//
Shot::Shot(sf::Texture& texture)
{
  shape_.setTexture(texture);
  shape_.setScale(0.2f, 0.2f);
}