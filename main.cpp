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

    sf::Texture errorTexture;
    if(!errorTexture.loadFromFile("resource/photos/Error.png"))
    {
        std::cout << "texture load error in: renderWindow" << std::endl;
    }

	//Creating the player
	Player player(sf::Vector2f(600,300),errorTexture,3);

<<<<<<< HEAD
        starMap.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
    }
    Game::spawn(new Enemy(sf::Vector2f(0,0), stuff.enemyShips, stuff.laser));

=======
	Game::spawn(new StarMap());
>>>>>>> master

	while (Game::window->isOpen())
    {
		//Update all objects
		sf::Time deltaTime = deltaClock.restart();
<<<<<<< HEAD
		for (unsigned n = 0; n < Game::objectVector->size(); n++)
        {
			if (!(*Game::objectVector)[n]->hasBeenDestroyed());
=======

		for (std::unique_ptr<Object>& currentObject : *Game::objectVector)
        {
			if (!currentObject->hasBeenDestroyed());
>>>>>>> master
			{
				(*Game::objectVector)[n]->update(deltaTime);
			}
		}

		for (unsigned n = 0; n < Game::objectVector->size(); n++)
		{
			if (!(*Game::objectVector)[n]->hasBeenDestroyed());
			{

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

		//Declaring X and Y values for the speed of player
		float speedX = 0.00f;
        float speedY = 0.00f;

        //Moves the player up with W or the up arrow
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            //sets the offset based on the speed
            speedX = 0.00f;
            speedY = -1.00f;
            player.movement(deltaTime,speedX,speedY);
        }
        //Moves the player down with S or the down arrow
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            speedX = 0.00f;
            speedY = 1.00f;
            player.movement(deltaTime,speedX,speedY);
        }
        //Moves the player left with A or the left arrow
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            speedX = -1.00f;
            speedY = 0.00f;
            player.movement(deltaTime,speedX,speedY);
        }
        //Moves the player right with D or the right arrow
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            speedX = 1.00f;
            speedY = 0.00f;
            player.movement(deltaTime,speedX,speedY);
        }

		//Frame-rate

<<<<<<< HEAD
	}
=======
    //Drawing the player object
    Game::window->draw(player);
    //Drawing the framerate clock
    Game::window->draw(Frame(frameClock, stuff.Arial));
    //displaying the window
    Game::window->display();

    }

>>>>>>> master
}

int main()
{
    //Main game window
    Game::setWindow(new sf::RenderWindow(sf::VideoMode(1368, 700), "Aluminum Dafaa Raiders"));

    //Used for dynamic objects
    Game::setObjectVector(new std::vector<std::unique_ptr<Object>>);

<<<<<<< HEAD
    //create resource object
	Resources stuff;

	//load resources
	if (!stuff.load()) {
		return EXIT_FAILURE;
	}

=======
    //sets openGL context to not wait and listen to this thread so we can render in another
>>>>>>> master
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
