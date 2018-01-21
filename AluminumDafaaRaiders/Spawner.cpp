#include "Spawner.h"
#include "Game.h"
#include "Resources.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"

Spawner::Spawner(sf::Time interval, int enemyType) : enemy(enemyType)
{
    setIntervalTime(interval);
}

void Spawner::update(sf::Time deltaTime)
{
    if (clock.getElapsedTime() >= intervalTime)
    {
		switch (enemy)
		{
		default:
		case 1:
			Game::spawn(new Enemy1(sf::Vector2f(rand() % 1300, -100), Resources::enemies, Resources::laser));
			break;
		case 2:
			Game::spawn(new Enemy2(sf::Vector2f(rand() % 1300, -100), Resources::enemies, Resources::laser));
			break;
		case 3:
			Game::spawn(new Enemy3(sf::Vector2f(rand() % 1300, -100), Resources::enemies, Resources::laser));
			break;
		case 4:
			Game::spawn(new Enemy4(sf::Vector2f(rand() % 1300, -100), Resources::enemies, Resources::laser));
			break;
		case 5:
			Game::spawn(new Enemy5(sf::Vector2f(rand() % 1300, -100), Resources::enemies, Resources::laser));
			break;
		}

        clock.restart();
    }
}

void Spawner::setIntervalTime(sf::Time interval)
{
    intervalTime = interval;

    clock.restart();
}
