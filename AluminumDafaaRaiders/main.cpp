//Standard includes
#include <vector>
#include <memory>
#include <iostream>
#include <ctime>

//SFML includes
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

//Our includes
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Framerate.h"
#include "Game.h"
#include "Resources.h"
#include "StarMap.h"
#include "ScoreDisplay.h"
#include "Spawner.h"

//Declare the used resources
sf::Font Resources::Arial;
sf::Texture Resources::errorTexture;
sf::Texture Resources::laser;
sf::Texture Resources::enemies;
sf::Texture Resources::player;

void renderWindow () {
	//Framerate clock
    sf::Clock frameClock;
	//Taylor's clock
    sf::Clock deltaClock;

	//load resources
	if (!Resources::load()) {
		std::cout << "resource load error in: renderWindow" << std::endl;
	}

	Game::spawn(new StarMap());

	Game::spawn(new ScoreDisplay(Resources::Arial, sf::Vector2f(Game::window->getSize().x, 0)));

	Game::spawn(new Spawner(sf::seconds(5), 1));
	Game::spawn(new Spawner(sf::seconds(15), 2));
	Game::spawn(new Spawner(sf::seconds(30), 3));
	Game::spawn(new Spawner(sf::seconds(10), 4));
	Game::spawn(new Spawner(sf::seconds(7), 5));

	//Creating the player
	Game::spawn(new Player(sf::Vector2f(600,300),Resources::player,3));

	while (Game::window->isOpen())
    {
        //Record the time since the last start of frame
        //Note that the first frame will vary wildly in length
        sf::Time deltaTime = deltaClock.restart();

		//Update all objects
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
		for (auto i = Game::objectVector->begin(); i != Game::objectVector->end();)
        {
			if ((*i)->hasBeenDestroyed())
			{
				i = Game::objectVector->erase(i);
			}
			else
			{
				i++;
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

		//Draw the health bar
		Game::window->draw(Game::healthBar);

        //Drawing the framerate clock
        //Game::window->draw(Frame(frameClock, Resources::Arial));
        //displaying the window
        Game::window->display();
    }

}

int main()
{
    //Seed current time
    std::srand(std::time(NULL));

    //Main game window
    Game::setWindow(new sf::RenderWindow(sf::VideoMode(1368, 700), "Aluminum Dafaa Raiders"));

    //Used for dynamic objects
    Game::setObjectVector(new std::vector<std::unique_ptr<Object>>);

    //sets openGL context to not wait and listen to this thread so we can render in another
	Game::window->setActive(false);

    //launches rendering thread with sf::thread and the window is automatically set to active in the new window
	sf::Thread thread(renderWindow);
    thread.launch();

	//Start the music
	sf::Music music;
	if (!music.openFromFile("resource/music/treasure.wav"))
	{
		return EXIT_FAILURE;
	}
	music.setLoop(true);
	music.play();

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
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    Game::isWindowClosing = true;
                }
                break;
            }
        }
        if (Game::isWindowClosing)
        {
            Game::window->close();
        }
    }

#ifdef _DEBUG
	//pause so devs can see any errors or couts in console window before it closes
	system("pause");
#endif // _DEBUG

	return 0;
}
