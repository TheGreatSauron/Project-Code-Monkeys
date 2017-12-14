//Standard includes
#include <vector>
#include <memory>
#include <iostream>

//SFML includes
#include <SFML/Graphics.hpp>

//Our includes
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Framerate.h"
#include "Game.h"
#include "Resources.h"
#include "StarMap.h"

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



	Player player(600,300,errorTexture,3);

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

	Game::spawn(new StarMap());

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
    }
}

int main()
{
    //Main game window
    Game::setWindow(new sf::RenderWindow(sf::VideoMode(1368, 700), "Aluminum Dafaa Raiders"));

    //Used for dynamic objects
    Game::setObjectVector(new std::vector<std::unique_ptr<Object>>);

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
    }

    //pause so devs can see any errors or couts in console window before it closes
    system("pause");
    return 0;
}
