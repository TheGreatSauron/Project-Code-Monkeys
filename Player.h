#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//#include "SFML/Graphics.hpp"
#include "Object.h"

//referencing this documentation: https://www.programiz.com/cpp-programming/operator-overloading

//Used to control each of the players capabilities
class Player : public Object
{
private:
    //Amount  of lives for the player
    int lives;
    //left and right movement
    int xMovement;
    //up and down movement
    int yMovement;

public:
    //overriding the virtual function in object.h
    virtual void update(sf::Time deltaTime) override;

    //? fix
    bool isDrawable;

    //default constructor passing in a default of lives at 3
    Player(int = 3, int = 0, int = 0);

    //adds or removes lives
    void manipulateLives(int);

    //defines the operator -- to subtract one from lives
    void operator --()
    {
        lives = lives - 1;
    }

    //defines the operator ++ to add one to lives
    void operator ++()
    {
        lives = lives + 1;
    }

};

#endif // PLAYER_H_INCLUDED
