#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//#include "SFML/Graphics.hpp"
#include "Object.h"

//referencing this documentation:
//https://www.programiz.com/cpp-programming/operator-overloading
//https://en.sfml-dev.org/forums/index.php?topic=13358.0
//https://en.sfml-dev.org/forums/index.php?topic=646.0
//http://www.cplusplus.com/forum/beginner/140541/

//Used to control each of the players capabilities
class Player : public Object
{
private:

    //Declaring the draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    //Amount  of lives for the player
    int lives;

    //declaring the sprite
    sf::Sprite sprite;

    //Invincibility clock
    std::unique_ptr<sf::Clock> invClock;

    //Clock to keep track of time between shots
    std::unique_ptr<sf::Clock> shootDelay;

public:
    //constructor
    Player(sf::Vector2f position, sf::Texture&, int tempLife = 3);

    //overriding the virtual function in object.h
    virtual void update(sf::Time deltaTime) override;

    //adds or removes lives
    void changeLives(int lives);

    //Gets the hitbox of the player
    virtual sf::FloatRect getGlobalBounds() const override;

    //Player dies
    void die();

    //Collide function for taking damage
    virtual void collide(std::unique_ptr<Object>& collisionObject) override;

    //Overloading the operator ++ and -- to add and subtract lives respectively
    void operator ++() { lives = lives + 1; }
    void operator --()
    {
        lives = lives - 1;
        if(lives <= 0)
        {
            die();
        }
    }
};

#endif // PLAYER_H_INCLUDED
