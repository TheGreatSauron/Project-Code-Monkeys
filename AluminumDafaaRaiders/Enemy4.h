#ifndef ENEMY4_H_INCLUDED
#define ENEMY4_H_INCLUDED
#include "Enemy.h"

class Enemy4 : public Enemy
{
protected:

	virtual void scorePoints() override;

public:

    Enemy4(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser);

    sf::FloatRect getGlobalBounds() const override;
};

#endif // ENEMY4_H_INCLUDED
