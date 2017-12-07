#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include "Object.h"

class Game
{
    static std::unique_ptr<sf::RenderWindow> window;
    static std::unique_ptr<std::vector<std::unique_ptr<Object>>> objectVector;

public:
    //enable the "to_string" function of std:: as code-blocks has bugs with it not working correctly
    template <typename T>
    std::string to_string(T value);

    spawn(Object* object);
};

#endif // GAME_H_INCLUDED
