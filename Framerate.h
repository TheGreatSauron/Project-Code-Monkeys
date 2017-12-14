#ifndef FRAMERATE_H_INCLUDED
#define FRAMERATE_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"

sf::Text Frame (sf::Clock& cock, sf::Font font)
{
    sf::Text frameCount(Game::to_string(1 / cock.restart().asSeconds()), font);
    return frameCount;
}

#endif // FRAMERATE_H_INCLUDED
