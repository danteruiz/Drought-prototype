#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

using namespace sf;
class Player
{
  private:
    bool isDead;


  public:
    RectangleShape player;
    Player();

};


#endif