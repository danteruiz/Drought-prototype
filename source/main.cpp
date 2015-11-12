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
    block.fRect = RectangleShape(Vector2f(150,30));
    block.fRect.setPosition(73,740);
    block.fRect.setFillColor(sf::Color(255,0,0));
    le.Blocks.push_back(block);


    Block block2(false);
    block2.fRect = RectangleShape(Vector2f(150,40));
    block2.fRect.setPosition(244,500);
    block2.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block2);


    Block block3(false);
    block3.fRect = RectangleShape(Vector2f(300,40));
    block3.fRect.setPosition(330,740);
    block3.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block3);


    Block block4(false);
    block4.fRect = RectangleShape(Vector2f(100,40));
    block4.fRect.setPosition(500, 550);
    block4.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block4);


    Block block5(false);
    block5.fRect = RectangleShape(Vector2f(100,40));
    block5.fRect.setPosition(650, 560);
    block5.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block5);

    Block block6(false);
    block6.fRect = RectangleShape(Vector2f(100,40));
    block6.fRect.setPosition(770, 740);

    block6.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block6);


    Block block7(false);
    block7.fRect = RectangleShape(Vector2f(100,40));
    block7.fRect.setPosition(987, 549);
    block7.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block7);


    Block block8(false);
    block8.fRect = RectangleShape(Vector2f(100,40));
    block8.fRect.setPosition(1098, 740);
    block8.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block8);


    Block block9(false);
    block9.fRect = RectangleShape(Vector2f(100,40));
    block9.fRect.setPosition(1365, 548);
    block9.fRect.setFillColor(sf::Color(255,255,0));
    le.Blocks.push_back(block9);
}



int main()
{

    RenderWindow window(VideoMode(1600, 800), "Drought");
    Event event;

    LightEngine le;
    Player player(50);
    player.player.setPosition(86,730);

    Light light;
    light.radius = 1300;
    light.angleSpeed = 180;
    light.position = Vector2f(800, -50);
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
        cout << " x position  = " << mouseX << " ::::: y position = " << mouseY << endl;
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