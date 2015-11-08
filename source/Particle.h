#ifndef PARTICLE_H
#define PARTICLE_H


#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace std;
class ParticleSystem: public sf::Drawable, public sf::Transformable
{

public:
  ParticleSystem(unsigned count);

  void setEmitter(sf::Vector2f position);
  void update(sf::Time elapsed);

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;


  void resetParticle(size_t index);

  struct Particle
  {
    sf::RectangleShape particle = sf::RectangleShape(sf::Vector2f(5.0,5.0));
    sf::Color color;
    sf::Vector2f velocity;
    sf::Time lifetime;
  };

  vector<Particle> m_particles;
  sf::VertexArray m_vertices;

  sf::Time m_lifetime;
  sf::Vector2f m_emitter;


};


#endif