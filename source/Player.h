#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Particle.h"
#include "LightEngine.h"

using namespace sf;
class Player
{
  private:
    ParticleSystem particles(500);

    bool isDead;
    bool onGround;
    float velocityX;
    float velocityY;
    float gravity;
    float acceleration;
    float jumpSpeed;

    void startJump();
    void endJump();


  public:
    RectangleShape player;
    Player();
    void HandleEvents();
    void update(LightEngine &le);

};

#endif