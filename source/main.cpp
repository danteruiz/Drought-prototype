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
    Block block;
    block.fRect = RectangleShape(Vector2f(600,70));
    block.fRect.setPosition(200,300);
    block.fRect.setFillColor(sf::Color(255,0,0));
    le.Blocks.push_back(block);

}

int main()
{

    RenderWindow window(VideoMode(1200, 800), "SFML works!");
    Event event;
    //const sf::Input Input = window.GetInput();
    //ParticleSystem particles(1000);

    LightEngine le;
    Player player;
    player.player.setPosition(200,200);


    player.player.setPosition(200,200);

    Light light;
    light.radius = 2000;
    light.angleSpeed = 360;
    light.position = Vector2f(600, 100);
    light.angle = 90;
    le.Lights.push_back(light);

    setBlocks(le);

    sf::Clock clock;
    sf:: Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f/60.f);


    while (window.isOpen())
    {

        while(accumulator > ups)
        {
            accumulator -= ups;
            player.update(le);
             player.HandleEvents();
            while (window.pollEvent(event))
            {


                if (event.type == sf::Event::Closed)
                {

                    window.close();
                }


            }

        }
        /*float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;
        sf::Vector2f mousePos = sf::Vector2f(mouseX,mouseY);
        float angle = util::getAngle(center, mousePos);
        */


        sf::Time elapsed = clock.restart();
        //particles.update(elapsed, angle);


        window.clear();
        window.draw(player.player);
        //window.draw(particles);
        window.draw(le.Blocks[0].fRect);
        le.Step(window);
        window.display();
        accumulator += clock.restart();
    }

    cout << " closing " << endl;

    return 0;

}




