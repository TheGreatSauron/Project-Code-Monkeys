#include "Player.h"

//constructor
Player::Player(sf::Vector2f position, sf::Texture& texture, int life)
{
    //setting the value of lives
    lives = life;
    //set the spite texture
    sprite.setTexture(texture);
    //set the spite position
    sprite.setPosition(0,0);
    //set the sprite scale
    sprite.setScale(1.5f,1.5f);
    //set the default direction
    sf::Vector2i direction(1, Down);
}
Player::~Player()
{

}

//update function
void Player::update(sf::Time deltaTime)
{
}

//
void Player::manipulateLives(int number)
{
    lives = lives + number; //sets the number of lives to be the passed in value to the function
}

sf::Sprite Player::getSprite() const
{
    return sprite;
}

//Moves the player up function
void Player::moveUp()
{
    direction.y = Up;

    sprite.move(0.00f, -speed);

}

void Player::moveDown()
{
    direction.y = Down;

    sprite.move(0.00f, speed);
}

void Player::moveRight()
{
    direction.y = Right;

    sprite.move(speed, 0.00f);
}

void Player::moveLeft()
{
    direction.y = Left;

    sprite.move(-speed, 0.00f);
}

void Player::setSpeed(float tempSpeed)
{
    speed = tempSpeed;
}
