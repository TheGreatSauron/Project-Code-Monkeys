#include "Enemy.h"
#include "Game.h"
#include "Spline.h"
#include "Projectile.h"
#include "ScoreDisplay.h"
#include "Object.h"

// Constructor
Enemy::Enemy(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Object(true, { "Enemy" }), laserTexture(laser)
{
    setPosition(position);
    sprite.setTexture(texture);

	spline.addNode(sf::Vector2f(std::rand()%1300, std::rand()%100));
	spline.addNode(sf::Vector2f(std::rand() % 1300, std::rand() % 200));
	spline.addNode(sf::Vector2f(std::rand() % 1300, std::rand() % 300));
	spline.addNode(sf::Vector2f(std::rand() % 1300, std::rand() % 500));
	//spline.offset(getPosition());
}

void Enemy::shootLaser()
{
	//Spawn lasers at the bottom of the enemy
	sf::Vector2f spawnLocation = getPosition();
	spawnLocation.x += getGlobalBounds().width / 2;
	spawnLocation.y += getGlobalBounds().height;

	// Spawn a laser
    Game::spawn(new Projectile(laserTexture, spawnLocation, sf::Vector2f(0, 200), {"Player"}));
}

void Enemy::scorePoints()
{
	Game::score += 100;
}

// Deal damage function
void Enemy::dealDamage(int damage)
{
    // Deals damage to current health
	health -= damage;

	// Destroys object if health falls to 0
	if (health <= 0)
	{
		scorePoints();

		destroy();
	}
}

// What to do every frame
void Enemy::update(sf::Time deltaTime)
{
    //Get movement this frame
    float movement = speed;

    //If next node is within reach, move there and then move on to next node
    if (spline.getRemainingDistance(getPosition()) < movement * deltaTime.asSeconds())
    {
		//Go to the current node
        movement -= spline.getRemainingDistance(getPosition()) * deltaTime.asSeconds();
        setPosition(spline.getCurrentNode());

		//Move on to next node
		spline.iterate();

		//Shoot a laser when a node is reached
		shootLaser();
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

//Happens when enemy collides with something
void Enemy::collide(std::unique_ptr<Object>& collisionObject)
{
	for (unsigned n = 0; n < collisionObject->collisionChannel.size(); n++)
	{
		if (collisionObject->collisionChannel[n] == "Projectile")
		{
			Enemy::dealDamage(1);
		}
	}
}
