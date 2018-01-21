#include "StarMap.h"
#include <ctime>
#include "Game.h"

void StarMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(stars);
}

StarMap::StarMap() : Object(true), speed(10)
{
    for (unsigned n = 0; n < 300; n++)
    {
        float x = rand()%Game::window->getSize().x;
        float y = rand()%Game::window->getSize().y;

        stars.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
    }
}

void StarMap::update(sf::Time deltaTime)
{
    for (unsigned n = 0; n < stars.getVertexCount(); n++)
    {
        stars[n].position.y += speed * deltaTime.asSeconds();
        if (stars[n].position.y > Game::window->getSize().y)
        {
            stars[n].position.y = 0;
        }
    }
}
