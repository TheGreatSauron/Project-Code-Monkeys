//Standard includes
#include <vector>
#include <memory>
#include <ctime>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Framerate.h"

//#include "Games::to_string.h"

//remove
#include <iostream>

int main()
{
    //Main game window
    sf::RenderWindow window(sf::VideoMode(1368, 600), "Aluminum Dafaa Raiders");

    //Use for creating objects
    //e.g. objectVector.push_back(std::unique_ptr<Object> (new Enemy()));
    std::vector<std::unique_ptr<Object>> objectVector;


    //Make stars!!!
    std::srand(std::time(NULL));
    sf::VertexArray starMap;
    for (unsigned n = 0; n < 200; n++)
    {
        float x = rand()%window.getSize().x;
        float y = rand()%window.getSize().y;

        starMap.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
    }

    //Taylor's shitty clock
    sf::Clock deltaClock;
    //Framerate clock
    sf::Clock frameClock;

    //Textures
    sf::Texture errorTexture;
    if (!errorTexture.loadFromFile("resources/photos/Error.png"))
        {
            return EXIT_FAILURE;
        }

    sf::Font Arial;
    if (!Arial.loadFromFile("resources/font/arial.ttf"))
    {
        return EXIT_FAILURE;
    }

    //Objects
    //test enemy
    objectVector.push_back(std::unique_ptr<Object> (new Enemy(sf::Vector2f(0,0), errorTexture, 100, 50)));

    //objectVector.push_back(std::unique_ptr<Object> (new Player(sf::Vector2f(600,350), errorTexture, 3)));

    Player player(sf::Vector2f(600,350),errorTexture, 3);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }


        //Update all objects
        sf::Time deltaTime = deltaClock.restart();
        for (std::unique_ptr<Object>& currentObject : objectVector)
        {
            if (!currentObject->hasBeenDestroyed());
            {
                currentObject->update(deltaTime);
            }
        }

        //Player Movement
        float speedX = 0.00f; //declares an X and Y value for movement
        float speedY = 0.00f;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //Move up
        {
            speedX = 0.00f;
            speedY = -1.00f;
            player.movement(deltaTime,speedX,speedY);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            speedX = 0.00f;
            speedY = 1.00f;
            player.movement(deltaTime,speedX,speedY);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            speedX = -1.00f;
            speedY = 0.00f;
            player.movement(deltaTime,speedX,speedY);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            speedX = 1.00f;
            speedY = 0.00f;
            player.movement(deltaTime,speedX,speedY);
        }

        //Do garbage collection, needs to iterate
        for (auto i = objectVector.begin(); i != objectVector.end(); i++)
        {
            if ((*i)->hasBeenDestroyed())
            {
                objectVector.erase(i);
                i--;
            }
        }

        //Reset window
        window.clear();

        //Draws background
        window.draw(starMap);

        window.draw(player);

        //Draw all drawable objects
        for (std::unique_ptr<Object>& currentObject : objectVector)
        {
            if (currentObject->isDrawable && !currentObject->hasBeenDestroyed())
            {
                window.draw(*currentObject);
            }
        }

        //framerate
        window.draw(Frame(frameClock, Arial));

        //Update window
        window.display();


    }

    return 8008;
}


