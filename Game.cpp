#include "Game.h"
#include <sstream>
#include <string>

template <typename T>
std::string Game::to_string(T value)
{
    //create an output string stream
    std::ostringstream os ;
    //throw the value into the string stream
    os << value ;
    //convert the string stream into a string and return
    return os.str() ;
}

