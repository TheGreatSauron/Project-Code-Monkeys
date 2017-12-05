#include "Player.h"

//constructor
Player::Player(sf::Vector2f Position, sf::Texture texture, int life)
{
    sprite.setTexture(texture);

    //determines the value of lives
    lives = life;
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


