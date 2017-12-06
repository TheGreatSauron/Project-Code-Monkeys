#include "Player.h"

//constructor
Player::Player(int life)
{
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

void Player::moveUp()
{
    Direction.y = Up;
    Spite.move(0, Speed);

}
