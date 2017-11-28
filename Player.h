#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "SFML/Graphics.hpp"
#include "Object.h"

//Used to control each of the players capabilities
class Player : public Object //Creating the Player class deriving from the Object class
{
public:
    int manipulate_lives(int,int); //first int = amount of lives, second int = lives lost

private:
    int life;

};

#endif // PLAYER_H_INCLUDED
