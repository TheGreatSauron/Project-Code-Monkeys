#include "Player.h"
#include <iostream>

//constructor
Player::Player(sf::Vector2f position, sf::Texture& texture, int life)
{
    //setting the value of lives
    lives = life;
    //set the spite texture
    sprite.setTexture(texture);
    //set the spite position
    sprite.setPosition(position);
    //set the sprite scale
    sprite.setScale(1.5f,1.5f);
    //set the default direction
    sf::Vector2i direction(0, Down);
}

Player::~Player()
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite,states);
}

//update function
void Player::update(sf::Time deltaTime)
{
}

void Player::movement(sf::Time& deltaTime, int directionValue)
{
    //speed *= deltaTime.asSeconds();
    switch (directionValue)
    {
        case 0: direction.y = Up;
                sprite.move(speed, 0.00f);
                std::cout << "Up\n";
                break;
        case 1: direction.y = Down;
                sprite.move(speed, 0.0f);
    }

}

//
void Player::changeLives(int number)
{
    lives = lives + number; //sets the number of lives to be the passed in value to the function

    if(lives <= 0)
    {
        //end game, close window or display a restart screen
    }
}

//Moves the player up function
void Player::moveUp(sf::Time& deltaTime)
{
    direction.y = Up;

    sprite.move(speed, 0.00f);

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
