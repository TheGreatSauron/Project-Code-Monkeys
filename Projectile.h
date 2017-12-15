#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include <SFML/graphics.hpp>
#include "Object.h"

//template <class Collider>
class Projectile : public Object
{
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite sprite;
    sf::Vector2f velocity;
public:
    virtual void update(sf::Time deltaTime) override;
    Projectile(sf::Texture& texture, sf::Vector2f position, sf::Vector2f projectileVelocity);

};

#endif // PROJECTILE_H_INCLUDED
