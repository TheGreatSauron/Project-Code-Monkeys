#include "Spline.h"
#include <cmath>

Spline::Spline() : currentNode(0)
{
    addNode(sf::Vector2f(0, 0));
}

void Spline::offset(sf::Vector2f offset)
{
    for (sf::Vector2f& currentNode : nodeVector)
    {
        currentNode += offset;
    }
}

void Spline::addNode(sf::Vector2f position)
{
    nodeVector.push_back(position);
}

sf::Vector2f Spline::getDirection(sf::Vector2f position) const
{
    sf::Vector2f direction;

    direction.x = nodeVector[currentNode].x - position.x;
    direction.y = nodeVector[currentNode].y - position.y;

    float magnitude = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
    direction.x /= magnitude;
    direction.y /= magnitude;

    return direction;
}

float Spline::getRemainingDistance(sf::Vector2f position) const
{
    sf::Vector2f direction;
    float distance;

    direction.x = nodeVector[currentNode].x - position.x;
    direction.y = nodeVector[currentNode].y - position.y;

    distance = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));

    return distance;
}

bool Spline::iterate()
{
    currentNode++;

    if (currentNode >= nodeVector.size())
    {
        currentNode = 0;

        return false;
    }

    return true;
}

sf::Vector2f Spline::getCurrentNode() const
{
    return nodeVector[currentNode];
}
