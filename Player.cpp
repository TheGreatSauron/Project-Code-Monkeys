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
    //Declaring X and Y values for the speed of player
    Game::playerInput.x = 0;
    Game::playerInput.y = 0;

    //Moves the player up with W or the up arrow
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //sets the offset based on the speed
        Game::playerInput.y += -1.00f;
    }
    //Moves the player down with S or the down arrow
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Game::playerInput.y += 1.00f;
    }
    //Moves the player left with A or the left arrow
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Game::playerInput.x += -1.00f;
    }
    //Moves the player right with D or the right arrow
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Game::playerInput.x += 1.00f;
    }

    float magnitude = std::sqrt(std::pow(Game::playerInput.x, 2) + std::pow(Game::playerInput.y, 2));
    if (magnitude)
    {
        Game::playerInput.x /= magnitude;
        Game::playerInput.y /= magnitude;
    }

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
