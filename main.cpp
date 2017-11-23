//Standard includes
#include <vector>
#include <memory>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"

int main()
{
    //Main game window
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    std::vector<std::unique_ptr<Object>> objectVector;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Update all objects
        sf::Time deltaTime;
        for (std::unique_ptr<Object>& currentObject : objectVector)
        {
            currentObject->update(deltaTime);
        }

        //Reset window
        window.clear();

        for (std::unique_ptr<Object>& currentObject : objectVector)
        {
            if (currentObject->isDrawable)
            {
                window.draw(*currentObject);
            }
        }

        //Update window
        window.display();
    }

    return 0;
}
