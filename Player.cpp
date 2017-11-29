#include "Player.h"

Player::Player(int life)
{
    lives = life;
}

void Player::manipulateLives(int manipulator)
{
    lives += manipulator;
}

void Player::update(sf::Time deltaTime)
{

}
