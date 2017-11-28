#include "Enemy.h"

// Constructor
Enemy::Enemy(int in_maxHealth = 1) : Object(true), maxHealth(in_maxHealth), health(in_maxHealth) {}

// Deal damage function
void Enemy::dealDamage(int damage)
{
    // Deals damage to current health
	health = health - damage;
	// Destroys object if health falls to 0
	if (health <= 0)
	{
		destroy();
	}
}
