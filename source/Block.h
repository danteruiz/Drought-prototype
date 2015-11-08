#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Block
{
  public:
    Block();
    RectangleShape fRect;
    bool allowBlock;

};

#endif