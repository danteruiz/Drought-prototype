#include <assert.h>
#include <SFML/Graphics.hpp>
#include "Light.h"
#include "Block.h"
#include "LightEngine.h"

using namespace sf;
using namespace std;

int main()
{

    RenderWindow window(VideoMode(800, 600), "SFML works!");
    Event event;

    LightEngine le;

    Light light;
    light.radius = 600;
    light.angleSpeed = 100;
    light.position = Vector2f(100,150);
    le.Lights.push_back(light);

    Block block;
    block.fRect = FloatRect(0,0,50,50);
    le.Blocks.push_back(block);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //cout << 1 / window.GetFrameTime()<<"\n";
        window.clear();
        //le.Blocks[0].fRect.left = window.GetInput().GetMouseX();
        //le.Blocks[0].fRect.top = window.GetInput().GetMouseY();
        window.draw(sf::Shape::Rectangle(le.Blocks[0].fRect, sf::Color(255,0,0)));
        le.Step(window);
        window.display();
    }

    return 0;

}