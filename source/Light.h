#ifndef LIGHT_H
#define LIGHT_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class Light
{
public:
  Vector2f position;
  Color color;
  float radius;
  float angleSpeed;
  float angle;
  bool dynamic;

  Light();
};

#endif