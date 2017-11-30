#include "Player.h"

Player::Player(int life)
{
    lives = life;
}

void Player::manipulateLives(int number)
{
    lives = lives + number; //sets the number of lives to be the passed in value to the function
}

void Player::playerMove(int movement)
{

}

void Player::update(sf::Time deltaTime)
{
}
