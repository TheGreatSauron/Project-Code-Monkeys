#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED


#include "SFML/Graphics.hpp"
#include "Object.h"

//Used to control each of the players capabilities
class Player : public Object //Creating the Player class deriving from the Object class
{
private:
    int lives;

public:
    Player(int = 3);
    //Player operator+(const Player&) const;
    virtual void update(sf::Time deltaTime) override;

    void manipulateLives(int);

};

#endif // PLAYER_H_INCLUDED
