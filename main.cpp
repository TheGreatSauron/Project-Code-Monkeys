//Standard includes
#include <vector>
#include <memory>

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
void movement () {
    Game::PspeedX = 0.f;
    Game::PspeedY = 0.f;

 //Moves the player up with W or the up arrow
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
            //sets the offset based on the speed
                Game::PspeedX += 0.00f;
                Game::PspeedY += -1.00f;
            }
            //Moves the player down with S or the down arrow
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                Game::PspeedX += 0.00f;
                Game::PspeedY += 1.00f;

            }
            //Moves the player left with A or the left arrow
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                Game::PspeedX += -1.00f;
                Game::PspeedY += 0.00f;

            }
            //Moves the player right with D or the right arrow
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                Game::PspeedX += 1.00f;
                Game::PspeedY += 0.00f;
            }
}


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

    Game::setPlayer(new Player(sf::Vector2f(600, 300), stuff.errorTexture));


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

    movement();
    Game::player->update(deltaTime);

    //Drawing the player object
    Game::window->draw(*Game::player);
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
            //case sf::Event
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
