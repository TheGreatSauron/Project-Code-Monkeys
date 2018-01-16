#include "Player.h"
#include "Object.h"
#include "Game.h"
#include <iostream>

//constructor
Player::Player(sf::Vector2f position, sf::Texture& texture, int life) : Object(true, {"Test"})
{
    //setting the value of lives
    lives = life;
    //set the player position
    setPosition(position);
    //set the spite texture
    sprite.setTexture(texture);
    //set the sprite scale
    sprite.setScale(1.5f,1.5f);
}

//draws the player
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();
    target.draw(sprite, states);
}

//update function
void Player::update(sf::Time deltaTime)
{
    sf::Vector2f movement = Game::playerInput;
    movement *= deltaTime.asSeconds() * 200.f;
    move(movement);
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

sf::FloatRect Player::getGlobalBounds() const
{
    sf::FloatRect hitbox(sprite.getLocalBounds());
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}
