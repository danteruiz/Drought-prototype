#include "Particle.h"

ParticleSystem::ParticleSystem(unsigned count):m_particles(count), m_vertices(sf::Points, count)
{
  m_emitter = sf::Vector2f(200.0,300.0);
  m_lifetime = sf::seconds(3);

}


void ParticleSystem::setEmitter(sf::Vector2f position)
{
  m_emitter = position;
}

 void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

        states.transform *= getTransform();

        states.texture = NULL;

        /*for(unsigned i = 0; i < m_particles.size();i++)
        {
          target.draw(m_particles[i].particle);

        }*/
        target.draw(m_vertices, states);

}

void ParticleSystem::update(sf::Time elapsed)
{
  for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            // update the particle lifetime
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero)
                resetParticle(i);

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
}


void ParticleSystem::resetParticle(size_t index)
{
  float angle = (rand() % 360) * 3.14f / 180.f;
        float speed = (rand() % 50) + 50.f;
        m_particles[index].velocity = sf::Vector2f(cos(angle) * speed, sin(angle) * speed);
        m_particles[index].lifetime = sf::milliseconds((rand() % 2000) + 1000);

        // reset the position of the corresponding vertex
        m_vertices[index].position = m_emitter;
}

