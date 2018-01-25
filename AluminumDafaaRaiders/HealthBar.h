#ifndef HEALTHBAR_H_INCLUDED
#define HEALTHBAR_H_INCLUDED

#include <SFML\Graphics.hpp>
#include "Object.h"

class HealthBar : public Object
{
	//Draw function
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//Text saying Health:
	sf::Text text;

	//The bar itself
	sf::RectangleShape inside, outline;

	//Keeps track of the maximum possible life
	int maxLife;

public:
	HealthBar(int life = 1);

	//Updates the health bar
	void updateHealth(int life);

	//Resets the maxlife of the health bar
	void reset(int life);

	virtual void update(sf::Time deltaTime) override;
};

#endif // HEALTHBAR_H_INCLUDED
