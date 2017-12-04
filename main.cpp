//Standard includes
#include <vector>
#include <memory>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"
#include "Player.h"

int main()
{
    //Main game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Aluminum Dafaa Raiders");

    //Use for creating objects
    //e.g. objectVector.push_back(std::unique_ptr<Object> (new Enemy()));
    std::vector<std::unique_ptr<Object>> objectVector;

    //Counts time between frames
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

            case sf::Event::KeyPressed: //possibly get rid of
                //call Player.playerMove(int) function
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
