#ifndef LIGHT_ENGINE_H
#define LIGHT_ENGINE_H

#include "Light.h"
#include "Block.h"
#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Shape.hpp>

using namespace std;
using namespace sf;

class LightEngine
{
public:
  void Step(RenderTarget &rt);
  vector <Light> Lights;
  vector <Block> Blocks;

private:
  void shineLight( Light &lig, RenderTarget &rt);

  static const float Distance(const Vector2f &p1, const Vector2f &p2);
  static const Vector2f GetCenter(const FloatRect &fr);

  struct FindDistance
  {
    FindDistance();
    float shortest;
    bool LightHitsBlock(Light &l, Block &b, const float cur_ang, float &reflength);
    bool start;
  };

  FindDistance findDis;

};
#endif