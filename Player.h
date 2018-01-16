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
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    //Amount  of lives for the player
    int lives;

    //declaring the sprite
    sf::Sprite sprite;

    //declaring the direction of the speed
    sf::Vector2i direction;

    //declaring direction values
    enum direction {Down, Left, Right, Up};

    bool borderCollision;

public:
    //constructor
    Player(sf::Vector2f position, sf::Texture&, int tempLife = 3);
    //destructor
    virtual ~Player();

    void borderCheck();

    //overriding the virtual function in object.h
    virtual void update(sf::Time deltaTime, borderCollision) override;

    //Player movement
    void movement(float speedX, float speedY);

    //adds or removes lives
    void changeLives(int lives);

    //Overloading the operator ++ and -- to add and subtract lives respectively
    void operator ++() { lives = lives + 1; }
    void operator --()
    {
        lives = lives - 1;
        if(lives <= 0)
        {
            //end game
        }
    }


};

#endif // PLAYER_H_INCLUDED
