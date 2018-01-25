#include "Projectile.h"
#include "Game.h"
#include <iostream>

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}

Projectile::Projectile(sf::Texture& texture, sf::Vector2f position, sf::Vector2f projectileVelocity, std::vector<std::string> collisionTags)
 : Object(true, collisionTags), velocity(projectileVelocity)
{
    sprite.setTexture(texture);
    sprite.setScale(0.1, 0.05);

	//Define the origin at the middle of the projectile
	setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);

    setPosition(position);

	collisionChannel.push_back("Projectile");
}

void Projectile::update(sf::Time deltaTime)
{
    move(velocity * deltaTime.asSeconds());

	if (getPosition().y - getGlobalBounds().height / 2 > Game::window->getSize().y)
	{
		destroy();
	}
	else if (getPosition().y + getGlobalBounds().height / 2 < 0)
	{
		destroy();
	}
}

sf::FloatRect Projectile::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 22.9, 35.35);
    hitbox.left = getPosition().x - hitbox.width / 2;
    hitbox.top = getPosition().y - hitbox.height / 2;
    return hitbox;
}

void Projectile::collide(std::unique_ptr<Object>& collisionObject)
{
	bool hitProjectile = false;
	for (unsigned n = 0; n < collisionObject->collisionChannel.size(); n++)
	{
		if (collisionObject->collisionChannel[n] == "Projectile")
		{
			hitProjectile = true;
		}
	}

	if (!hitProjectile)
	{
		destroy();
	}
}
