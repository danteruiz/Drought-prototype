#include "Player.h"
#include <math.h>


Player::Player()
{

  isDead = false;
  onGround = false;
  gravity = .5;
  velocityY = 4.0;
  velocityX = 4.0;
  acceleration = -1.0;
  jumpSpeed = -12;

  player = RectangleShape(Vector2f(20,20));

}

void Player::HandleEvents()
{

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-5.0, 0.0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(5.0, 0.0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
          startJump();
        }

}


void Player::update(LightEngine &le)
{
      if(!onGround)
      {
        velocityY = acceleration;
        acceleration += gravity;
      }
      player.move(0.0, velocityY);

      for(unsigned i = 0; i < le.Blocks.size(); i++)
      {
            if(player.getGlobalBounds().intersects(le.Blocks[i].fRect.getGlobalBounds()))
            {
              velocityY = 0.0;
              onGround = true;

            }else onGround = false;

      }

}

void Player::startJump()
{
      velocityY = 0.0;
      acceleration = jumpSpeed;
      onGround = false;
}


void Player::endJump()
{
    if(velocityY < -6.0)
      velocityY = -6.0;
}
