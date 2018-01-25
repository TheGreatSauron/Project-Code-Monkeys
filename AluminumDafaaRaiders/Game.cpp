#include "Game.h"

void Game::spawn(Object* object)
{
    objectVector->push_back(std::unique_ptr<Object>(object));
}

void Game::setObjectVector(std::vector<std::unique_ptr<Object>>* newObjectVector)
{
    objectVector.reset(newObjectVector);
}

void Game::setWindow(sf::RenderWindow* newWindow)
{
    window.reset(newWindow);
}

std::unique_ptr<sf::RenderWindow> Game::window;
std::unique_ptr<std::vector<std::unique_ptr<Object>>> Game::objectVector;
int Game::score = 0;
sf::Vector2f Game::playerInput(0, 0);
bool Game::isWindowClosing = false;
