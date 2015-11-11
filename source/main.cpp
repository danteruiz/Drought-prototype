#include <assert.h>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Light.h"
#include "Block.h"
#include "LightEngine.h"
#include "Player.h"
#include "Particle.h"
#include "util.h"

using namespace sf;
using namespace std;

void setBlocks(LightEngine &le)
{
    Block block(true);
    block.fRect = RectangleShape(Vector2f(70,70));
    block.fRect.setPosition(200,700);
    block.fRect.setFillColor(sf::Color(255,0,0));
    le.Blocks.push_back(block);


    Block block2(false);
    block2.fRect = RectangleShape(Vector2f(150,70));
    block2.fRect.setPosition(300,400);
    block2.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block2);


}

int main()
{

    RenderWindow window(VideoMode(1200, 800), "SFML works!");
    Event event;
    sf::Vector2f center = sf::Vector2f(300.0,300.0);

    LightEngine le;
    Player player(50);
    player.player.setPosition(200,200);


    player.player.setPosition(200,200);

    Light light;
    light.radius = 2000;
    light.angleSpeed = 120;
    light.position = Vector2f(600, 100);
    light.angle = 90;
    le.Lights.push_back(light);

    setBlocks(le);

    sf::Clock clock;
    ;


    while (window.isOpen())
    {
    		float mouseX = sf::Mouse::getPosition(window).x;
        	float mouseY = sf::Mouse::getPosition(window).y;
       	 	sf::Vector2f mousePos = sf::Vector2f(mouseX,mouseY);
        	float angle = util::getAngle(player.player.getPosition(), mousePos);

    		sf::Time elapsed = clock.restart();

            player.update(le,elapsed, angle);
            player.HandleEvents();

            while (window.pollEvent(event))
            {


                if (event.type == sf::Event::Closed)
                {

                    window.close();
                }


            }


        ;







        window.clear();
        window.draw(player.player);
        window.draw(player.getParticle());
        window.draw(le);
        le.Step(window);
        window.display();

    }

    cout << " closing " << endl;

    return 0;

}




