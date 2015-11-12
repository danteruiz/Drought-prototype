#include "Block.h"

Block::Block(bool isFixed)
{
   fixed = isFixed;
   allowBlock = true;
   fRect = RectangleShape(Vector2f(0,0));
}


void Block::update(sf::Vector2f position)
{

    if(!fixed)
    {
    	if(position.x < fRect.getPosition().x + fRect.getSize().x /2)
    	{
    		fRect.move(6.0, 0.0);
    	}else if(position.x > fRect.getPosition().x + (fRect.getSize().x /2))
    	{
    		fRect.move(-6.0, 0.0);
    	
    	}
    }

}

