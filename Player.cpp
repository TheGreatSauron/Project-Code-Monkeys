#include "Player.h"

void Player::update(sf::Time deltaTime)
{
}

Player::Player(int life, int x, int y)
{
    lives = life;
    xMovement = x;
    yMovement = y;
}

void Player::manipulateLives(int number)
{
    lives = lives + number; //sets the number of lives to be the passed in value to the function
}

/*void Player::playerMove(int x, int y)
{

}*/

