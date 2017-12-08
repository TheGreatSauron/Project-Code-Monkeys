#ifndef FRAMERATE_H_INCLUDED
#define FRAMERATE_H_INCLUDED

#include "to_string.h"

sf::Text Frame (sf::Clock& cock, sf::Font font) {

    sf::Text frameCount(to_string(1 / cock.restart().asSeconds()), font);
    return frameCount;
}

#endif // FRAMERATE_H_INCLUDED
