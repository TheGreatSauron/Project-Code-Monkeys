#include "Game.h"

void Game::spawn(Object* object)
{
    objectVector->push_back(std::unique_ptr<Object> (object));
}

void Game::setObjectVector(std::vector<std::unique_ptr<Object>>* newObjectVector)
{
    objectVector.reset(newObjectVector);
}

void Game::setWindow(sf::RenderWindow* newWindow)
{
    window.reset(newWindow);
}

void Game::setPlayer(Player* newPlayer)
{
    player.reset(newPlayer);
}

std::unique_ptr<sf::RenderWindow> Game::window;
std::unique_ptr<std::vector<std::unique_ptr<Object>>> Game::objectVector;
std::unique_ptr<Player> Game::player;
int Game::score;
float Game::PspeedX;
float Game::PspeedY;
