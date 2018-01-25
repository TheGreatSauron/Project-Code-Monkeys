#include "Enemy3.h"
#include "Game.h"
#include "Projectile.h"

void Enemy3::scorePoints()
{
	Game::score += 1000;
}

Enemy3::Enemy3(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 50;
    health = 5;

    sprite.setTextureRect(sf::IntRect(126, 2, 152, 46));
}

sf::FloatRect Enemy3::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 152, 46);
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}

void Enemy3::shootLaser()
{
	//Spawn lasers at the bottom of the enemy
	sf::Vector2f spawnLocation = getPosition();
	spawnLocation.y += getGlobalBounds().height;

	// Spawn a laser on the left
	Game::spawn(new Projectile(laserTexture, spawnLocation, sf::Vector2f(0, 200), { "Player" }));

	spawnLocation.x += getGlobalBounds().width;

	// Spawn a laser on the right
	Game::spawn(new Projectile(laserTexture, spawnLocation, sf::Vector2f(0, 200), { "Player" }));
}
