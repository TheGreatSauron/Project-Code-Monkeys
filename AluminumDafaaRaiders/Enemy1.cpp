#include "Enemy1.h"

Enemy1::Enemy1(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 100;
    health = 1;

    sprite.setTextureRect(sf::IntRect(7, 4, 37, 40));
}

sf::FloatRect Enemy1::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 37, 40);
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}
