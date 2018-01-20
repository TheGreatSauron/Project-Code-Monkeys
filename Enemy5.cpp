#include "Enemy5.h"

Enemy5::Enemy5(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 100;
    health = 1;

    sprite.setTextureRect(sf::IntRect(354, 6, 41, 28));

    //Add nodes go in constructor
    //THESE ARE TEST NODES AND ALL NEW ENEMEYS WILL FOLLOW THIS PATH
    spline.addNode(sf::Vector2f(700, 700));
    spline.addNode(sf::Vector2f(700, 200));
    spline.offset(getPosition());
}

sf::FloatRect Enemy5::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 41, 28);
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}
