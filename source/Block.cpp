#include "Block.h"

Block::Block(bool isFixed)
{
   fixed = isFixed;
   allowBlock = true;
   fRect = RectangleShape(Vector2f(0,0));
}


void Block::update(sf::Vector2f position)
{
    cout << "doing block update" << endl;

}

