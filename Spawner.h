#ifndef SPAWNER_H_INCLUDED
#define SPAWNER_H_INCLUDED

#include <SFML\graphics.hpp>
#include "Object.h"

class Spawner : public Object
{
    //Clock to keep track of when to spawn enemies
    sf::Clock clock;

    //Time between spawns
    sf::Time intervalTime;

public:
    Spawner(sf::Time interval);

    //override update function from object
    virtual void update(sf::Time deltaTime) override;
};

#endif // SPAWNER_H_INCLUDED
