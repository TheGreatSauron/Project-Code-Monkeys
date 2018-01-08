#include "Projectile.h"

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}

Projectile::Projectile(sf::Texture& texture, sf::Vector2f position, sf::Vector2f projectileVelocity)
 : Object(true), velocity(projectileVelocity)
{
    sprite.setTexture(texture);
    sprite.setScale(0.1, 0.05);

    setPosition(position);

    collider.push_back("Test");
}

void Projectile::update(sf::Time deltaTime)
{
    move(velocity * deltaTime.asSeconds());
}

sf::FloatRect Projectile::getGlobalBounds() const
{
    sf::FloatRect hitbox(sprite.getLocalBounds());
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}
