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

int main()
{

    RenderWindow window(VideoMode(1200, 800), "SFML works!");
    Event event;
    ParticleSystem particles(1000);

    LightEngine le;
    bool onGround = false;

    sf::Vector2f center = sf::Vector2f(200.0,300.0);

    Player player;
    sf::Clock clock;

    player.player.setPosition(200,200);

    Light light;
    light.radius = 2000;
    light.angleSpeed = 360;
    light.position = Vector2f(600, 100);
    light.angle = 90;
    le.Lights.push_back(light);

    Block block;
    block.fRect = RectangleShape(Vector2f(50,70));
    block.fRect.setPosition(200,300);
    block.fRect.setFillColor(sf::Color(255,0,0));
    le.Blocks.push_back(block);

    while (window.isOpen())
    {

        for(unsigned i = 0; i < le.Blocks.size(); i++){
            if(player.player.getGlobalBounds().intersects(le.Blocks[i].fRect.getGlobalBounds()))
            {
                onGround = true;
            }else onGround = false;

        }

        if(onGround == false)
        {
            player.player.move(0.0, 3.0);

        }
        while (window.pollEvent(event))
        {

            if(event.key.code == 0)
                player.player.move(-5.0 , 0.0);

            if(event.key.code == sf::Keyboard::D)
                player.player.move(5.0,0.0);

            if(event.key.code == sf::Keyboard::Space)
                player.player.move(0.0, -5.0);

            if (event.type == sf::Event::Closed)
            {
            	
                window.close();
            }

            
        }

        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;
        sf::Vector2f mousePos = sf::Vector2f(mouseX,mouseY);
        float angle = util::getAngle(center, mousePos);

       
       
        sf::Time elapsed = clock.restart();
        particles.update(elapsed, angle);

        
        window.clear();
        window.draw(player.player);
        window.draw(particles);
        window.draw(le.Blocks[0].fRect);
        le.Step(window);
        window.display();
    }

    cout << " closing " << endl;

    return 0;

}









void SetUp()
{

}




