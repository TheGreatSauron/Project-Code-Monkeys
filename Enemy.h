#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "Object.h"

class Enemy : public Object
{
private:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	// Current Health
	int health;
	// Max Health, should not change
	const int maxHealth;

public:
    // Constructor declaration
	Enemy(sf::Texture& texture, int in_maxHealth = 1);
    // Deals damage to current health
	void dealDamage(int damage);
	virtual void update(sf::Time deltaTime) override;
    sf::Sprite sprite;

};

#endif
