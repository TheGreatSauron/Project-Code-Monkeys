#include "Enemy3.h"

Enemy3::Enemy3(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 100;
    health = 1;

    sprite.setTextureRect(sf::IntRect(126, 2, 152, 46));

    //Add nodes go in constructor
    //THESE ARE TEST NODES AND ALL NEW ENEMEYS WILL FOLLOW THIS PATH
    spline.addNode(sf::Vector2f(700, 700));
    spline.addNode(sf::Vector2f(700, 200));
    spline.offset(getPosition());
}

sf::FloatRect Enemy3::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 152, 46);
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}
