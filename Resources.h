#ifndef RESOURCES_H_INCLUDED
#define RESOURCES_H_INCLUDED
#include <iostream>

class Resources{
public:
	//font
	static sf::Font Arial;
	//errorTexture
	static sf::Texture errorTexture;
    //laser
    static sf::Texture laser;
    //Enemies
    static sf::Texture enemies;
    //Player
    static sf::Texture player;
	//loads all textures when called, if one fails it returns false, if not then true
	static bool load() {
		//load arial
		if (!Arial.loadFromFile("resource/font/arial.ttf")) {
			std::cout << "arial";
			return false;
		}

		//load Texture
		if (!errorTexture.loadFromFile("resource/photos/Error.png")) {
			std::cout << "errorTxt";
			return false;
		}

		//load laser
		if (!laser.loadFromFile("resource/photos/laser.png"))
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
        //load enemies
		if (!enemies.loadFromFile("resource/photos/Enemies.png"))
        {
            std::cout << "enemiesTxt";
            return false;
        }

        //load player
		if (!player.loadFromFile("resource/photos/Player.png"))
        {
            std::cout << "playerTxt";
            return false;
        }
		return true;
	}

private:

};

#endif // RESOURCES_H_INCLUDED
