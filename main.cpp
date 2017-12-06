//Standard includes
#include <vector>
#include <memory>
#include <ctime>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"
#include "Enemy.h"
#include "Framerate.h"

int main()
{
    //Main game window
    sf::RenderWindow window(sf::VideoMode(1368, 700), "Aluminum Dafaa Raiders");

    //Use for creating objects
    //e.g. objectVector.push_back(std::unique_ptr<Object> (new Enemy()));
    std::vector<std::unique_ptr<Object>> objectVector;

    //Make stars!!!
    std::srand(std::time(NULL));
    sf::VertexArray starMap;
    for (unsigned n = 0; n < 100; n++)
    {
        float x = rand()%window.getSize().x;
        float y = rand()%window.getSize().y;

        starMap.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
    }

    //Counts time between frames, this should be the last thing created before the game starts
    //Taylor's shitty clock
    sf::Clock deltaClock;
    //Justin's framerate clock
    sf::Clock frameClock;

    sf::Texture errorTexture;
    if (!errorTexture.loadFromFile("Error.png"))
        {
            return EXIT_FAILURE;
        }

    sf::Font Arial;
    if (!Arial.loadFromFile("resources/font/arial.ttf"))
    {
        return EXIT_FAILURE;
    }

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

    return 8008;
}


