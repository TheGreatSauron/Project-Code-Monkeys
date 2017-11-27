#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "SFML/Graphics.hpp"
#include "Object.h"

//Used to control each of the players capabilities
class Player : public Object
{
protected:
    int lives;
    int livesLost;

public:
    int getLives();


private:

};

#endif // PLAYER_H_INCLUDED
