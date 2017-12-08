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
#include "Game.h"

int main()
{
    //Main game window
    Game::setWindow(new sf::RenderWindow(sf::VideoMode(1000, 600), "Aluminum Dafaa Raiders"));

    //Use for creating objects
    //e.g. objectVector.push_back(std::unique_ptr<Object> (new Enemy()));
    Game::setObjectVector(new std::vector<std::unique_ptr<Object>>);

    //Make stars!!!
    std::srand(std::time(NULL));
    sf::VertexArray starMap;
    for (unsigned n = 0; n < 200; n++)
    {
        float x = rand()%Game::window->getSize().x;
        float y = rand()%Game::window->getSize().y;

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

    while (Game::window->isOpen())
    {
        sf::Event event;
        while (Game::window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                Game::window->close();
                break;
            }
        }

        //Update all objects
        sf::Time deltaTime = deltaClock.restart();
        for (std::unique_ptr<Object>& currentObject : *Game::objectVector)
        {
            if (!currentObject->hasBeenDestroyed());
            {
                currentObject->update(deltaTime);
            }
        }

        //Do garbage collection, needs to iterate
        for (auto i = Game::objectVector->begin(); i != Game::objectVector->end(); i++)
        {
            if ((*i)->hasBeenDestroyed())
            {
                Game::objectVector->erase(i);
                i--;
            }
        }

        //Reset window
        Game::window->clear();

        //Draws background
        Game::window->draw(starMap);

        //Draw all drawable objects
        for (std::unique_ptr<Object>& currentObject : *Game::objectVector)
        {
            if (currentObject->isDrawable && !currentObject->hasBeenDestroyed())
            {
                Game::window->draw(*currentObject);
            }
        }
        //framerate
        Game::window->draw(Frame(frameClock, Arial));
        frameClock.restart();

        //Update window
        Game::window->display();
    }

    return EXIT_SUCCESS;
}


