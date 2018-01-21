#include "Spawner.h"
#include "Game.h"
#include "Enemy1.h"
#include "Resources.h"

Spawner::Spawner(sf::Time interval)
{
    setIntervalTime(interval);
}

void Spawner::update(sf::Time deltaTime)
{
    if (clock.getElapsedTime() >= intervalTime)
    {
        Game::spawn(new Enemy1(sf::Vector2f(rand()%1300, -100), Resources::enemies, Resources::laser));

        clock.restart();
    }
}

void Spawner::setIntervalTime(sf::Time interval)
{
    intervalTime = interval;

    clock.restart();
}
