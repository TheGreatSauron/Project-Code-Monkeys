#include "Enemy.h"

// Constructor
Enemy::Enemy(sf::Texture& texture, int in_maxHealth) : Object(true), maxHealth(in_maxHealth), health(in_maxHealth)
{
    sprite.setTexture(texture);
}

// Deal damage function
void Enemy::dealDamage(int damage)
{
    // Deals damage to current health
	health -= damage;
	// Destroys object if health falls to 0
	if (health <= 0)
	{
		destroy();
	}
}

void Enemy::update(sf::Time deltaTime)
{

}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}
