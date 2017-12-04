#ifndef SPLINE_H_INCLUDED
#define SPLINE_H_INCLUDED

#include <vector>
#include <SFML/System.hpp>

class Spline
{
    //Internal storage to keep track of spline nodes
    std::vector<sf::Vector2f> nodeVector;
    unsigned currentNode;

public:
    //Constructs a spline with one node at the origin
    Spline();

    //Offsets all nodes in the spline by some amount
    void offset(sf::Vector2f offset);

    //Adds a new node to the spline
    void addNode(sf::Vector2f position);

    //Gets the direction of travel to the next node
    sf::Vector2f getDirection(sf::Vector2f position) const;

    //Finds the remaining distance to the next node
    float getRemainingDistance(sf::Vector2f position) const;

    //Iterates to the next node
    //returns true if there is a node to travle to next
    //returns false if you have reached the end of the spline
    bool iterate();

    //Gets the location of the current Node
    sf::Vector2f getCurrentNode() const;
};

#endif // SPLINE_H_INCLUDED
