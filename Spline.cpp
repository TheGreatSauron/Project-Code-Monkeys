#include "Spline.h"
#include <cmath>

Spline::Spline() : currentNode(0) {}

void Spline::offset(sf::Vector2f offset)
{
    for (Node& currentNode : nodeVector)
    {
        currentNode.position += offset;
    }
}

void Spline::addNode(sf::Vector2f position, float curve)
{
    Node newNode;
    newNode.position = position;
    newNode.curve = curve;

    nodeVector.push_back(newNode);
}

sf::Vector2f Spline::getDirection(sf::Vector2f position)
{
    sf::Vector2f direction;
    if (nodeVector[currentNode].curve == 0)
    {
        direction.x = position.x - nodeVector[currentNode].position.x;
        direction.y = position.y - nodeVector[currentNode].position.y;

        float magnitude = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
        direction.x /= magnitude;
        direction.y /= magnitude;
    }
    else
    {
        float nodeDistance;
        sf::Vector2f ;
    }

    return direction;
}

bool Spline::iterate()
{
    currentNode++;

    return !currentNode >= nodeVector.size();
}
