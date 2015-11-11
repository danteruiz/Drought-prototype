#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

using namespace std;

using namespace sf;

class Block
{
  private:
    bool fixed;
  public:
    Block(bool isFixed);
    RectangleShape fRect;
    bool allowBlock;
    void update(sf::Vector2f position);

};

#endif