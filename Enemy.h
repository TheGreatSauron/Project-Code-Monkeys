#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "Object.h"
#include "Spline.h"

class Enemy : public Object
{
private:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	// Current Health
	int health;
	// Max Health, should not change
	const int maxHealth;
	// Enemy speed
	float speed;

public:
    // Constructor declaration
	Enemy(sf::Vector2f postition, sf::Texture& texture, int in_maxHealth = 1, float in_speed = 1);
    // Deals damage to current health
	void dealDamage(int damage);
	// What occurs every frame
	virtual void update(sf::Time deltaTime) override;
    // Declares sprite
    sf::Sprite sprite;
    // Spline class
    Spline spline;

};

#endif
