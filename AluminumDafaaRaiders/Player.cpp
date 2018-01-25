#include "Player.h"
#include "Object.h"
#include "Game.h"
#include "Projectile.h"
#include "Resources.h"
#include <SFML\Audio.hpp>

//constructor
Player::Player(sf::Vector2f position, sf::Texture& texture, int life) : Object(true, {"Player"})
{
    //setting the value of lives
    lives = life;
    //set the player position
    setPosition(position);
    //set the spite texture
    sprite.setTexture(texture);
    //set the sprite scale down to reasonable size
    sprite.setScale(0.1f,0.15f);
	//Set the health bar
	Game::healthBar.reset(lives);
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

    //Normalizes the vector to get rid of diagonal fast movement
    float magnitude = std::sqrt(std::pow(Game::playerInput.x, 2) + std::pow(Game::playerInput.y, 2));
    if (magnitude)
    {
        Game::playerInput.x /= magnitude;
        Game::playerInput.y /= magnitude;
    }

	//Move the player
    sf::Vector2f movement = Game::playerInput;
    movement *= deltaTime.asSeconds() * 300.f;
    move(movement);

	//Keep the player in the screen
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
	}
	else if (getPosition().x + getGlobalBounds().width > Game::window->getSize().x)
	{
		setPosition(Game::window->getSize().x - getGlobalBounds().width, getPosition().y);
	}
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
	}
	else if (getPosition().y + getGlobalBounds().height > Game::window->getSize().y)
	{
		setPosition(getPosition().x, Game::window->getSize().y - getGlobalBounds().height);
	}

    if (shootDelay)
    {
        if (shootDelay->getElapsedTime() >= sf::seconds(1))
        {
            shootDelay.reset();
        }
    }

    //Allow the player to shoot
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (!shootDelay)
        {
			//Spawn lasers at the bottom of the enemy
			sf::Vector2f spawnLocation = getPosition();
			spawnLocation.x += getGlobalBounds().width / 2;

            Game::spawn(new Projectile(Resources::laser, spawnLocation, sf::Vector2f(0, -350), {"Enemy"}));

            shootDelay.reset(new sf::Clock());
        }
    }

    if (invClock)
    {
        if (invClock->getElapsedTime() >= sf::seconds(1.5))
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

	//Update the health bar
	Game::healthBar.updateHealth(lives);

	//Play sound
	Game::playSound(Resources::playerHit);

    //determines if the player has less than or 0 lives to then end the game
    if(lives <= 0)
    {
        die();
    }
}

sf::FloatRect Player::getGlobalBounds() const
{
    sf::FloatRect hitbox(sf::FloatRect(0, 0, 60.5, 60.3));
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y + 10;
    return hitbox;
}

void Player::die()
{
	std::cout << "You have died!\n";
	std::cout << "Your score was " << Game::score << "\n";

    destroy();

    Game::isWindowClosing = true;
}

void Player::collide(std::unique_ptr<Object>& collisionObject)
{
    if (!invClock)
    {
        changeLives(-1);

        invClock.reset(new sf::Clock());
    }
}
