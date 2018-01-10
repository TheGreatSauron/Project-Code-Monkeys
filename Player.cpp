#include "Player.h"
#include "Object.h"
#include <iostream>
#include "Object.h"

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

//destructor
Player::~Player()
{
}

//draws the player
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite,states);
}

//update function
void Player::update(sf::Time deltaTime)
{
}

//moves the player
void Player::movement(sf::Time& deltaTime, float speedX, float speedY)
{
    //adding X and Y to deltaTime as a value of seconds
    speedX += deltaTime.asSeconds();
    speedY += deltaTime.asSeconds();

    //moves the player bases on the offset of the passed in X and Y value
    sprite.move(speedX,speedY);
}

//changes the players amount of lives
void Player::changeLives(int tempLife)
{
    //sets the number of lives to be equal to itself + the passed in number
    lives = lives + tempLife; //sets the number of lives to be the passed in value to the function

    //determines if the player has less than or 0 lives to then end the game
    if(lives <= 0)
    {
        //end game, close window or display a restart screen
    }
}
