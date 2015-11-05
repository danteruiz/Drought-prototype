#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics/Rect.hpp>

using namespace sf;

class Block
{
  public:
    Block();
    FloatRect fRect;
    bool allowBlock;

};

#endif