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

void Game::setPlayer(Player* newPlayer)
{
    player.reset(newPlayer);

    //If there is none, create a dummy object to sync with player
    if (playerIndex == -1)
    {
        spawn(newPlayer);
    }
}

std::unique_ptr<Object>& Game::getPlayerDummy()
{
    return (*objectVector)[playerIndex];
}

std::unique_ptr<sf::RenderWindow> Game::window;
std::unique_ptr<std::vector<std::unique_ptr<Object>>> Game::objectVector;
std::unique_ptr<Player> Game::player;
int Game::score = 0;
int Game::playerIndex = -1;
