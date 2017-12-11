#ifndef FRAMERATE_H_INCLUDED
#define FRAMERATE_H_INCLUDED

#include "game.h"

sf::Text Frame (sf::Clock& cock, sf::Font font) {
    sf::Text frameCount(Game::to_string(1 / cock.restart().asSeconds()), font);
    return frameCount;
}

#endif // FRAMERATE_H_INCLUDED
