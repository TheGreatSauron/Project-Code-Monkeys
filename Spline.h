#ifndef SPLINE_H_INCLUDED
#define SPLINE_H_INCLUDED

#include <vector>
#include <SFML/System.hpp>

class Spline
{
    struct Node
    {
        sf::Vector2f position;
        float curve;
    };
    std::vector<Node> nodeVector;
    unsigned currentNode;

public:
    Spline();
    void offset(sf::Vector2f offset);
    void addNode(sf::Vector2f position, float curve = 0);
    sf::Vector2f getDirection(sf::Vector2f position);
    bool iterate();
};

#endif // SPLINE_H_INCLUDED
