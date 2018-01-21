#ifndef ENEMY1_H_INCLUDED
#define ENEMY1_H_INCLUDED
#include "Enemy.h"
class Enemy1 : public Enemy
{

public:

    Enemy1(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser);

    sf::FloatRect getGlobalBounds() const override;
};

#endif // ENEMY1_H_INCLUDED
