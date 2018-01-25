#ifndef STARMAP_H_INCLUDED
#define STARMAP_H_INCLUDED

#include <SFML/graphics.hpp>
#include "Object.h"

class StarMap : public Object
{
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray stars;
    float speed;

public:
    //Create star map
    StarMap();

    //Moves stars
    void update(sf::Time deltaTime) override;
};

#endif // STARMAP_H_INCLUDED
