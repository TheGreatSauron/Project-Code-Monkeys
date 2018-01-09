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

    sf::Texture errorTexture;
    if(!errorTexture.loadFromFile("resource/photos/Error.png"))
    {
        std::cout << "texture load error in: renderWindow" << std::endl;
    }

	//Creating the player
	Player player(sf::Vector2f(600,300),errorTexture,3);

	Game::spawn(new StarMap());

	Game::spawn(new ScoreDisplay(stuff.Arial, sf::Vector2f(Game::window->getSize().x, 0)));

	Game::spawn(new Enemy(sf::Vector2f(0, 200), stuff.errorTexture, stuff.laser));

	while (Game::window->isOpen())
    {
		//Update all objects
		sf::Time deltaTime = deltaClock.restart();
		for (unsigned n = 0; n < Game::objectVector->size(); n++)
        {
			if (!(*Game::objectVector)[n]->hasBeenDestroyed());
			{
				(*Game::objectVector)[n]->update(deltaTime);
			}
		}

		//DO NOT TOUCH
		//Very delicate and can break very easily, take care to not change without careful deliberation
		for (unsigned n = 0; n < Game::objectVector->size(); n++)
		{
			if (!(*Game::objectVector)[n]->hasBeenDestroyed())
			{
			    for (unsigned i = n+1; i < Game::objectVector->size(); i++)
                {
                    //Checks if both objects are alive and colliding
                    if ((!(*Game::objectVector)[i]->hasBeenDestroyed())
                        && (*Game::objectVector)[n]->getGlobalBounds().intersects((*Game::objectVector)[i]->getGlobalBounds()))
                    {
                        //Checks for matching collision channels
                        bool areColliding = false;
                        for (unsigned a = 0; a < (*Game::objectVector)[n]->collisionChannel.size(); a++)
                        {
                            for (unsigned b = 0; b < (*Game::objectVector)[i]->collisionChannel.size(); b++)
                            {
                                if ((*Game::objectVector)[n]->collisionChannel[a] == (*Game::objectVector)[i]->collisionChannel[b])
                                {
                                    areColliding = true;
                                }
                            }
                        }

                        //If there are matching channels, both objects collide with one another
                        //Effects are object specific
                        if (areColliding)
                        {
                            (*Game::objectVector)[n]->collide((*Game::objectVector)[i]);
                            (*Game::objectVector)[i]->collide((*Game::objectVector)[n]);
                        }
                    }
                }
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

    //Drawing the player object
    Game::window->draw(player);
    //Drawing the framerate clock
    Game::window->draw(Frame(frameClock, stuff.Arial));
    //displaying the window
    Game::window->display();

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
    }

    //pause so devs can see any errors or couts in console window before it closes
    system("pause");
    return 0;
}
