//Standard includes
#include <vector>
#include <memory>
#include <iostream>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"
#include "Enemy.h"
#include "Framerate.h"
#include "Game.h"
#include "Resources.h"
#include "StarMap.h"
#include "ScoreDisplay.h"

void renderWindow () {
	//Framerate clock
    sf::Clock frameClock;
	//Taylor's clock
    sf::Clock deltaClock;

	//add resources object
	Resources stuff;

	//load resources
	if (!stuff.load()) {
		std::cout << "resource load error in: renderWindow" << std::endl;
	}

	Game::spawn(new StarMap());

	Game::spawn(new ScoreDisplay(stuff.Arial, sf::Vector2f(Game::window->getSize().x, 0)));

	while (Game::window->isOpen())
    {
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

		//Draw all drawable objects
		for (std::unique_ptr<Object>& currentObject : *Game::objectVector)
        {
			if (currentObject->isDrawable && !currentObject->hasBeenDestroyed())
            {
				Game::window->draw(*currentObject);
			}
		}

		//Frame-rate
		Game::window->draw(Frame(frameClock, stuff.Arial));

		//Update window
		Game::window->display();
	}
}

int main()
{
    //Main game window
    Game::setWindow(new sf::RenderWindow(sf::VideoMode(1368, 700), "Aluminum Dafaa Raiders"));

    //Used for dynamic objects
    Game::setObjectVector(new std::vector<std::unique_ptr<Object>>);


    /* Not needed, loaded twice
    //create resource object
	Resources stuff;

	//load resources
	if (!stuff.load()) {
		return EXIT_FAILURE;
	}*/

    //sets openGL context to not wait and listen to this thread so we can render in another
	Game::window->setActive(false);

    //launches rendering thread with sf::thread and the window is automatically set to active in the new window
	sf::Thread thread(renderWindow);
    thread.launch();

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
    }

    //pause so devs can see any errors or couts in console window before it closes
    system("pause");
    return 0;
}
