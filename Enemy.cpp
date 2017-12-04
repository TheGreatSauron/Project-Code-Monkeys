#include "Enemy.h"
#include "Spline.h"

// Constructor
Enemy::Enemy(sf::Vector2f position, sf::Texture& texture, int in_maxHealth, float in_speed) : Object(true),
maxHealth(in_maxHealth), health(in_maxHealth), speed(in_speed)
{
    setPosition(position);

    // Loads in texture from argument
    sprite.setTexture(texture);

    // Add nodes go in constructor
    // spline.addNode(sf::Vector2f(100, 0));
    // spline.addNode(sf::Vector2f(0, 100));
    // spline.offset(getPosition());
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

// What to do every frame
void Enemy::update(sf::Time deltaTime)
{
    //Get movement this frame
    float movement = speed;

    //If next node is within reach, teleport and move on to next node
    if (spline.getRemainingDistance(getPosition()) < movement * deltaTime.asSeconds())
    {
        movement -= spline.getRemainingDistance(getPosition()) * deltaTime.asSeconds();
        setPosition(spline.getCurrentNode());
        //If this is the last node, destroy the object
        if (!spline.iterate())
        {
            destroy();
        }
    }

    //Move remaining distance
    sf::Vector2f direction = spline.getDirection(getPosition());
    direction *= movement * deltaTime.asSeconds();
    setPosition(getPosition() + direction);
}

// Draws enemy/error
void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}
