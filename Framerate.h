#ifndef FRAMERATE_H_INCLUDED
#define FRAMERATE_H_INCLUDED


#include <string>
#include <SFML/Graphics.hpp>
#include "to_string.h"

sf::Text Frame (sf::Clock cock, sf::Font font) {

    sf::Text frameCount(to_string((1 / cock.restart().asSeconds()) / 60), font);
    return frameCount;
}

#endif // FRAMERATE_H_INCLUDED
