#include "Enemy1.h"

Enemy1::Enemy1(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 100;
    health = 1;

    sprite.setTextureRect(sf::IntRect(7, 4, 37, 40));

    //Add nodes go in constructor
    //THESE ARE TEST NODES AND ALL NEW ENEMEYS WILL FOLLOW THIS PATH
    spline.addNode(sf::Vector2f(700, 700));
    spline.addNode(sf::Vector2f(700, 200));
    spline.offset(getPosition());
}
