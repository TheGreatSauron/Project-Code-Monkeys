#include "Enemy2.h"

Enemy2::Enemy2(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 100;
    health = 1;

    sprite.setTextureRect(sf::IntRect(51, 1, 66, 98));

    //Add nodes go in constructor
    //THESE ARE TEST NODES AND ALL NEW ENEMEYS WILL FOLLOW THIS PATH
    spline.addNode(sf::Vector2f(700, 700));
    spline.addNode(sf::Vector2f(700, 200));
    spline.offset(getPosition());
}

sf::FloatRect Enemy2::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 66, 98);
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}
