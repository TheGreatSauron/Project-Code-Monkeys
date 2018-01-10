#ifndef SCOREDISPLAY_H_INCLUDED
#define SCOREDISPLAY_H_INCLUDED

#include <SFML/graphics.hpp>
#include "Object.h"

class ScoreDisplay : public Object
{
    //Actual drawn figure
    sf::Text text;

    //Origin is in the top right corner
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    ScoreDisplay(sf::Font& font, sf::Vector2f position);

    void update(sf::Time deltaTime);
};

#endif // SCOREDISPLAY_H_INCLUDED
