#include "Projectile.h"

Projectile::Projectile(sf::Texture& texture, sf::Vector2f projectileVelocity) : Object(true)
{
    sprite.setTexture(texture);
}

void Projectile::update(sf::Time deltaTime)
{

}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}
