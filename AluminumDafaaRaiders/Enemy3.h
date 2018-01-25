#ifndef ENEMY3_H_INCLUDED
#define ENEMY3_H_INCLUDED

#include "Enemy.h"

class Enemy3 : public Enemy
{

public:

    Enemy3(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser);

    sf::FloatRect getGlobalBounds() const override;
};

#endif // ENEMY3_H_INCLUDED
