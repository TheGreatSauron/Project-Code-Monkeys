#include "Player.h"
#include "Object.h"
#include "Game.h"
#include <iostream>

//constructor
Player::Player(sf::Vector2f position, sf::Texture& texture, int life) : Object(true, {"Player"}), invClock()
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

    if (invClock)
    {
        if (invClock->getElapsedTime() >= sf::seconds(3))
        {
            invClock.reset();
        }
    }
}

//changes the players amount of lives
void Player::changeLives(int tempLife)
{
    //sets the number of lives to be equal to itself + the passed in number
    lives += tempLife; //sets the number of lives to be the passed in value to the function

    //determines if the player has less than or 0 lives to then end the game
    if(lives <= 0)
    {
        die();
    }
}

sf::FloatRect Player::getGlobalBounds() const
{
    sf::FloatRect hitbox(sprite.getLocalBounds());
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}

void Player::die()
{
    destroy();

    Game::isWindowClosing = true;
}

void Player::collide(std::unique_ptr<Object>& collisionObject)
{
    if (!invClock)
    {
        changeLives(-1);
    }

    invClock.reset(new sf::Clock());
}
