#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>
#include "Particle.h"
#include "LightEngine.h"
using namespace sf;
class Player
{
  private:
    ParticleSystem particle;
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
    Player(unsigned count);
    void HandleEvents();
    void update(LightEngine &le, sf::Time elasped, float angle);
    void isHit(Color pixel);
    ParticleSystem getParticle();

};

#endif