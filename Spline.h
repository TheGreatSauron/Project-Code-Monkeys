#ifndef SPLINE_H_INCLUDED
#define SPLINE_H_INCLUDED

#include <queue>
#include <SFML/System.hpp>

class Spline
{
    std::queue<sf::Vector2f> positionQueue;
    float curve;

public:
    Spline();
    void offset(sf::Vector2f offset);
    sf::Vector2f getDirection(sf::Vector2f position);
};

#endif // SPLINE_H_INCLUDED
