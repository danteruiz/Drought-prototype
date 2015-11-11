#include "Player.h"
#include <math.h>


Player::Player(unsigned count):particle(count)
{

  isDead = false;
  onGround = false;
  gravity = 0.6;
  velocityY = 4.0;
  velocityX = 4.0;
  acceleration = -3.0;
  jumpSpeed = -12;

  player = RectangleShape(Vector2f(20,20));

}

void Player::HandleEvents()
{

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-10.0, 0.0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(10.0, 0.0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
        	if(onGround)
          		startJump();
        }

}

void Player::update(LightEngine &le, sf::Time elapsed,float angle)
{
	  particle.setEmitter(player.getPosition());
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
              break;

            }else
            {
              onGround = false;

            }

      }


      particle.update(elapsed, angle, le);



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

ParticleSystem Player::getParticle()
{
	return particle;
}
