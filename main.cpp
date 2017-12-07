//Standard includes
#include <vector>
#include <memory>
#include <ctime>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"
//<<<<<<< HEAD
#include "Player.h"
//=======
#include "Enemy.h"
//<<<<<<< HEAD
//>>>>>>> 59e99038ff55868f4829d185fdc017da5dd42ada
//=======
#include "Framerate.h"
//>>>>>>> ac667b488d5aa758e690ee5353e5d52434c38e0c

int main()
{
    //Main game window
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Aluminum Dafaa Raiders");

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

    //Counts time between frames, this should be the last thing created before the game starts
    //Update clock
    sf::Clock deltaClock;
    //Framerate clock
    sf::Clock frameClock;

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
    Player player(/*playerTexture*/); //Player

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

        //Player Movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)); //Move up
            //player.moveUp();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
            //player.moveDown();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
            //player.moveLeft();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
            //player.moveRight();


        //Update all objects
        sf::Time deltaTime = deltaClock.restart();
        for (std::unique_ptr<Object>& currentObject : objectVector)
        {
            if (!currentObject->hasBeenDestroyed());
            {
                currentObject->update(deltaTime);
            }
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
        frameClock.restart();

        //Update window
        window.display();


    }

    return EXIT_SUCCESS;
}


