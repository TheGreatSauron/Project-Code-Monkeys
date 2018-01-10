#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include <SFML/graphics.hpp>
#include <typeinfo>
#include <iostream>
#include "Object.h"

//For debug only, delete later
/*
class Collision : public Object
{
    sf::RectangleShape rect;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states = getTransform();
        target.draw(rect, states);
    }
public:
    Collision(sf::Vector2f position) : Object(true), rect(sf::Vector2f(100, 100))
    {
        setPosition(position);
        rect.setFillColor(sf::Color::Red);

        collider.push_back("Test");
    }
    void update(sf::Time deltaTime) override
    {
    }
    void collide(std::unique_ptr<Object>& collisionObject) override
    {
        std::cout << "Collision\n";
    }
    sf::FloatRect getGlobalBounds() const override
    {
        sf::FloatRect hitbox = rect.getLocalBounds();
        hitbox.top = getPosition().y;
        hitbox.left = getPosition().x;
        return hitbox;
    }
};
*/

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

#endif // PROJECTILE_H_INCLUDED
