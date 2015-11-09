#include "Particle.h"

ParticleSystem::ParticleSystem(unsigned count):m_particles(count), m_vertices(sf::Points, count)
{
  m_emitter = sf::Vector2f(200.0,300.0);
  m_lifetime = sf::seconds(2);

}


void ParticleSystem::setEmitter(sf::Vector2f position)
{
  m_emitter = position;
}

 void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

        states.transform *= getTransform();

        states.texture = NULL;

        for(unsigned i = 0; i < m_particles.size();i++)
        {
          target.draw(m_particles[i].particle, states);

        }

}

void ParticleSystem::update(sf::Time elapsed, float angle)
{
  for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            
            if (p.lifetime <= sf::Time::Zero)
                resetParticle(i, angle);

            float speed = m_particles[i].velocity.x;
            float moveX = 10 * cos(angle * PI / 180);
            float moveY = 10 * sin (angle * PI / 180);
            m_particles[i].particle.move(moveX,moveY);

            
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_particles[i].color.a = static_cast<sf::Uint8>(ratio * 255);
            m_particles[i].color.r = 30;
        }
}


void ParticleSystem::resetParticle(size_t index, float direction)
{
        float angle = direction;
        float speed = (rand() % 50) + 50.f;
        m_particles[index].velocity = sf::Vector2f(speed, speed);
        m_particles[index].lifetime = sf::milliseconds((rand() % 2000) + 1000);

        // reset the position of the corresponding vertex
        m_particles[index].particle.setPosition(m_emitter);
}

