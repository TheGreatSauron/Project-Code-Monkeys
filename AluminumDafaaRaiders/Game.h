#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include "Object.h"
#include "Player.h"
#include "HealthBar.h"

struct Game
{
    static std::unique_ptr<sf::RenderWindow> window;
    static std::unique_ptr<std::vector<std::unique_ptr<Object>>> objectVector;
    static int score;
    static sf::Vector2f playerInput;
    static bool isWindowClosing;
	static HealthBar healthBar;

    //enable the "to_string" function of std:: as code-blocks has bugs with it not working correctly
    template <typename T>
    static std::string to_string(T value);

    //Create new dynamic object
    static void spawn(Object* object);

    //Sets a new objectVector
    static void setObjectVector(std::vector<std::unique_ptr<Object>>* newObjectVector);

    //Sets a new game window
    static void setWindow(sf::RenderWindow* newWindow);
};

template <typename T>
std::string Game::to_string(T value)
{
    //create an output string stream
    std::ostringstream os ;
    //throw the value into the string stream
    os << value ;
    //convert the string stream into a string and return
    return os.str();
}

#endif // GAME_H_INCLUDED
