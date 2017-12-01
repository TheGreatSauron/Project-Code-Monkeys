#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//#include "SFML/Graphics.hpp"
#include "Object.h"

//referencing this documentation: https://www.programiz.com/cpp-programming/operator-overloading

//Used to control each of the players capabilities
class Player : public Object //Creating the Player class deriving from the Object class
{
private:
    int lives; //Amount of lives for the player
    int xMovement; //left and right movement
    int yMovement; //up and down movement

public:
    //Player operator+(const Player&) const;
    virtual void update(sf::Time deltaTime) override; //overriding the virtual function in object.h
    bool isDrawable; //? fix

    Player(int = 3, int = 0, int = 0); //constructor with the default lives being 3
    void manipulateLives(int); //does the same thing as -- or ++ but can have any value inputted

    void operator --() //defines the operator -- to subtract one from lives
    {
        lives = lives - 1;
    }

    void operator ++() //defines the operator ++ to add one to lives
    {
        lives = lives + 1;
    }

};

#endif // PLAYER_H_INCLUDED
