#ifndef RESOURCES_H_INCLUDED
#define RESOURCES_H_INCLUDED
#include <iostream>

class Resources{

public:
	//font
	sf::Font Arial;
	//errorTexture
	sf::Texture errorTexture;
    //laser
    sf::Texture laser;
    //enemy ships
    sf::Texture enemyShips;
	//loads all textures when called, if one fails it returns false, if not then true
	bool load() {
		//load arial
		if (!Arial.loadFromFile("resources/font/arial.ttf")) {
			std::cout << "arial";
			return false;
		}

		//load Texture
		if (!errorTexture.loadFromFile("resources/photos/Error.png")) {
			std::cout << "errorTxt";
			return false;
		}

		//load laser
		if (!laser.loadFromFile("resources/photos/laser.png"))
        {
            std::cout << "laserTxt";
            return false;
        }

        //load Enemy ships
        //(7, 4, 37, 40) First Ship
        //(51, 1, 66, 98) Second Ship
        //(126, 2, 152, 46) Third Ship
        //(289, 5, 59, 29) Fourth Ship
        //(354, 6, 41, 28) Fifth Ship
		if (!enemyShips.loadFromFile("resources/photos/Enemies.png"))
        {
            std::cout << "Enemies";
            return false;
        }
		return true;
	}

private:

};

#endif // RESOURCES_H_INCLUDED
