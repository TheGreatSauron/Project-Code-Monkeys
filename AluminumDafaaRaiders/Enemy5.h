#ifndef ENEMY5_H_INCLUDED
#define ENEMY5_H_INCLUDED
#include "Enemy.h"

class Enemy5 : public Enemy
{

public:

    Enemy5(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser);

    sf::FloatRect getGlobalBounds() const override;
};

#endif // ENEMY5_H_INCLUDED
