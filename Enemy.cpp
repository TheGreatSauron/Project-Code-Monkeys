#include "Enemy.h"
#include "Game.h"
#include "Spline.h"
#include "Projectile.h"
#include "ScoreDisplay.h"
#include "Object.h"

// Constructor
Enemy::Enemy(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Object(true), laserTexture(laser)
{
    setPosition(position);
    sprite.setTexture(texture);
}

void Enemy::shootLaser()
{
    Game::spawn(new Projectile(laserTexture, getPosition(), sf::Vector2f(0, -100)));
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

        // If this is the last node, destroy the object
        if (!spline.iterate())
        {
            destroy();
        }
        else
        {
            shootLaser();
        }
    }

    //Move remaining distance
    sf::Vector2f direction = spline.getDirection(getPosition());
    direction *= movement * deltaTime.asSeconds();
    move(direction);
}

// Draws enemy/error
void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}

void Enemy::collide(std::unique_ptr<Object>& collisionObject)
{
    Enemy::dealDamage(1);
}





