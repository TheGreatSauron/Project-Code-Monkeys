#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "Object.h"

class Enemy : public Object
{
protected:
	// Current Health
	int health;
	// Max Health, should not change
	const int maxHealth;

public:
    // Deals damage to current health
	void dealDamage(int damage);
	// Constructor declaration
	Enemy(int in_maxHealth);

};

#endif
