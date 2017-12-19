#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include <SFML/graphics.hpp>
#include "Object.h"

template <class Collider>
class Projectile : public Object
{
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite sprite;
    sf::Vector2f velocity;
public:
    Projectile(sf::Texture& texture, sf::Vector2f position, sf::Vector2f projectileVelocity);
    virtual void update(sf::Time deltaTime) override;
    virtual sf::FloatRect getGlobalBounds() const override;
};

template<class Collider>
void Projectile<Collider>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}

template<class Collider>
Projectile<Collider>::Projectile(sf::Texture& texture, sf::Vector2f position, sf::Vector2f projectileVelocity)
 : Object(true, true), velocity(projectileVelocity)
{
    sprite.setTexture(texture);
    sprite.setScale(0.1, 0.05);

    setPosition(position);
}

template<class Collider>
void Projectile<Collider>::update(sf::Time deltaTime)
{
    move(velocity * deltaTime.asSeconds());
}

template<class Collider>
sf::FloatRect Projectile<Collider>::getGlobalBounds() const
{
    sf::FloatRect hitbox(sprite.getLocalBounds());
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}

#endif // PROJECTILE_H_INCLUDED
