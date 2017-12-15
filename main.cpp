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
#include "Resources.h"

void renderWindow () {
	//Framerate clock
    sf::Clock frameClock;
	//Taylor's shitty clock
    sf::Clock deltaClock;

	//add resources object
	Resources stuff;

	//load resources
	if (!stuff.load()) {
		std::cout << "load error in: renderWindow" << std::endl;
	}

    //Make stars!!!
    std::srand(std::time(NULL));
    sf::VertexArray starMap;

    for (unsigned n = 0; n < 300; n++){
        float x = rand()%Game::window->getSize().x;
        float y = rand()%Game::window->getSize().y;

        starMap.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
    }
    Game::spawn(new Enemy(sf::Vector2f(0,0), stuff.errorTexture, stuff.laser));


	while (Game::window->isOpen()) {
		//Update all objects
		sf::Time deltaTime = deltaClock.restart();
		for (unsigned n = 0; n < Game::objectVector->size(); n++) {
			if (!(*Game::objectVector)[n]->hasBeenDestroyed());
			{
				(*Game::objectVector)[n]->update(deltaTime);
			}
		}

		//Do garbage collection, needs to iterate
		for (auto i = Game::objectVector->begin(); i != Game::objectVector->end(); i++) {
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
		for (std::unique_ptr<Object>& currentObject : *Game::objectVector) {
			if (currentObject->isDrawable && !currentObject->hasBeenDestroyed()) {
				Game::window->draw(*currentObject);
			}
		}

		//Frame-rate
		Game::window->draw(Frame(frameClock, stuff.Arial));

		//Update window
		Game::window->display();

	}
}

int main() {
    //Main game window
    Game::setWindow(new sf::RenderWindow(sf::VideoMode(1368, 700), "Aluminum Dafaa Raiders"));

    //Use for creating objects
    //e.g. objectVector.push_back(std::unique_ptr<Object> (new Enemy()));
    Game::setObjectVector(new std::vector<std::unique_ptr<Object>>);

    //create resource object
	Resources stuff;

	//load resources
	if (!stuff.load()) {
		return EXIT_FAILURE;
	}

	Game::window->setActive(false);

	sf::Thread thread(renderWindow);
    thread.launch();

    while (Game::window->isOpen()) {
        sf::Event event;
        while (Game::window->pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::Closed:
                Game::window->close();
                break;
            }
        }
    }

system("pause");
return 8008;
}


