#ifndef ENEMY4_H_INCLUDED
#define ENEMY4_H_INCLUDED
#include "Enemy.h"

class Enemy4 : public Enemy
{

public:

    Enemy4(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser);
};

#endif // ENEMY4_H_INCLUDED
