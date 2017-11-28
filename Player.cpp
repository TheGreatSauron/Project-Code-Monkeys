#include "Player.h"

Player::manipulate_lives(int total_life, int damage)
{
    life = total_life - damage;

    return life;
}

