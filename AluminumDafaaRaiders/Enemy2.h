#ifndef ENEMY2_H_INCLUDED
#define ENEMY2_H_INCLUDED
#include "Enemy.h"

class Enemy2 : public Enemy
{
protected:

	virtual void scorePoints() override;

public:

    Enemy2(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser);

    sf::FloatRect getGlobalBounds() const override;
};

#endif // ENEMY2_H_INCLUDED
