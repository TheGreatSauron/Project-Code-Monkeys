#include "Spawner.h"
#include "Game.h"
#include "Enemy.h"
#include "Resources.h"

Spawner::Spawner(sf::Time interval) : intervalTime(interval)
{
}

void Spawner::update(sf::Time deltaTime)
{
    if (clock.getElapsedTime() >= intervalTime)
    {
        Game::spawn(new Enemy(sf::Vector2f(0, 0), Resources::errorTexture, Resources::laser));

        clock.restart();
    }
}
