#ifndef SPLINE_H_INCLUDED
#define SPLINE_H_INCLUDED

#include <vector>
#include <SFML/System.hpp>

class Spline
{
    std::vector<sf::Vector2f> nodeVector;
    unsigned currentNode;

public:
    Spline();
    void offset(sf::Vector2f offset);
    void addNode(sf::Vector2f position);
    sf::Vector2f getDirection(sf::Vector2f position) const;
    float getRemainingDistance(sf::Vector2f position) const;
    bool iterate();
    sf::Vector2f getCurrentNode() const;
};

#endif // SPLINE_H_INCLUDED
