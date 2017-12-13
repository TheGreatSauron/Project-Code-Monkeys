#ifndef RESOURCES_H_INCLUDED
#define RESOURCES_H_INCLUDED
#include <iostream>

class Resources{
public:
	//font
	sf::Font Arial;
	//errorTexture
	sf::Texture errorTexture;

	//loads all textures when called, if one fails it returns false, if not then true
	bool load() {
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
		return true;
	}

private:

};

#endif // RESOURCES_H_INCLUDED
