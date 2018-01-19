#include "Menu.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

Menu::Menu()
{
}

void Menu::goToMenu()
{
    //if escape is pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
    }
}

void Menu::inMenu(int Variable)
{
    if(Variable == 0)
    {
        exit();
    }
    //while return is not pressed
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        //draw menu screen
    }
}

void Menu::exit()
{

}
