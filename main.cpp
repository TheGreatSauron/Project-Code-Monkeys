//Standard includes
#include <vector>
#include <memory>
#include <ctime>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"
#include "Enemy.h"

int main()
{
    //Main game window
    sf::RenderWindow window(sf::VideoMode(1368, 700), "Aluminum Dafaa Raiders");

    //Use for creating objects
    //e.g. objectVector.push_back(std::unique_ptr<Object> (new Enemy()));
    std::vector<std::unique_ptr<Object>> objectVector;

    std::srand(std::time(NULL));
    sf::VertexArray starMap;
    for (unsigned n = 0; n < 100; n++)
    {
        float x = rand()%window.getSize().x;
        float y = rand()%window.getSize().y;

        starMap.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
    }

    sf::Texture errorTexture;
    if (!errorTexture.loadFromFile("Error.png"))
    {
        return EXIT_FAILURE;
    }

    //Counts time between frames, this should be the last thing created before the game starts
    sf::Clock frameClock;

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
        sf::Time deltaTime = frameClock.restart();
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

        //Update window
        window.display();
    }

    return 0;
}

/*
Base class
Spline spline;

Derived class
spline.addNode(sf::Vector2f(100, 0));
spline.offset(getPosition());

Base class update
float speed;
if (speed >= spline.getRemainingDistance())
{
    setPosition(spline.getCurrentNode());
    speed -= spline.getRemainingDistance();
    if (!spline.iterate())
    {
        //something, movement over
    }
}
sf::Vector2f direction = spline.getDirection(getPosition());
direction *= speed;
setPosition(getPosition() + direction);
*/
