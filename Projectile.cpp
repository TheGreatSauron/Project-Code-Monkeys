#include "Projectile.h"

Projectile::Projectile(sf::Texture& texture, sf::Vector2f position, sf::Vector2f projectileVelocity)
 : Object(true), velocity(projectileVelocity)
{
    sprite.setTexture(texture);
    sprite.setScale(0.1, 0.05);

    setPosition(position);
}

void Projectile::update(sf::Time deltaTime)
{
    move(velocity * deltaTime.asSeconds());
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}
