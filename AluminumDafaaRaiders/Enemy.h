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

	// Enemy speed
	float speed;

	// Shoots a laser
	virtual void shootLaser();

	//Scores the points of the enemy
	virtual void scorePoints();

public:

    // Constructor declaration
	Enemy(sf::Vector2f postition, sf::Texture& texture, sf::Texture& laser);

    // Deals damage to current health
	void dealDamage(int damage);

	// What occurs every frame
	virtual void update(sf::Time deltaTime) override;

	virtual void collide(std::unique_ptr<Object>& collisionObject) override;

    // Declares sprites
    sf::Sprite sprite;
    sf::Texture& laserTexture;

    // Spline class
    Spline spline;

};

#endif
