#ifndef ENEMY3_H_INCLUDED
#define ENEMY3_H_INCLUDED

#include "Enemy.h"

class Enemy3 : public Enemy
{
protected:

	virtual void scorePoints() override;

public:

    Enemy3(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser);

    sf::FloatRect getGlobalBounds() const override;

	void shootLaser() override;
};

#endif // ENEMY3_H_INCLUDED
