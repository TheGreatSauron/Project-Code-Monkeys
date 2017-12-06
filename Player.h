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

public:
    //default constructor passing in a default of lives at 3
    Player(int = 3);

    //overriding the virtual function in object.h
    virtual void update(sf::Time deltaTime) override;

    //adds or removes lives
    void manipulateLives(int);

    //Overloading the operator ++ and -- to add and subtract lives respectively
    void operator ++() { lives = lives + 1; }
    void operator --() { lives = lives - 1; }


    //Player movement
    void Moveup();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setSpeed();

    sf::Sprite sprite;

};

#endif // PLAYER_H_INCLUDED
