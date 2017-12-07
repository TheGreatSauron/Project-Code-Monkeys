#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//#include "SFML/Graphics.hpp"
#include "Object.h"

//referencing this documentation:
//https://www.programiz.com/cpp-programming/operator-overloading
//https://en.sfml-dev.org/forums/index.php?topic=13358.0
//https://en.sfml-dev.org/forums/index.php?topic=646.0

//Used to control each of the players capabilities
class Player : public Object
{
private:
    //Amount  of lives for the player
    int lives;

    //declaring the sprite
    sf::Sprite sprite;

    //declaring the direction of the speed
    sf::Vector2i direction;

    enum direction {Up, Down, Left, Right};

    float speed;

public:
    //constructor
    Player(int = 3);
    //overloaded constructor
    Player(int,sf::Texture&);
    //destructor
    ~Player();

    //Player movement
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setSpeed(float);

    //access function
    sf::Sprite getSprite() const;


    //overriding the virtual function in object.h
    virtual void update(sf::Time deltaTime) override;

    //adds or removes lives
    void manipulateLives(int);

    //Overloading the operator ++ and -- to add and subtract lives respectively
    void operator ++() { lives = lives + 1; }
    void operator --() { lives = lives - 1; }

};

#endif // PLAYER_H_INCLUDED
