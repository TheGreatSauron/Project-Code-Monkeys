//SFML includes
#include <SFML/Graphics.hpp>

//Our includes

int main()
{
    //Main game window
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Reset window
        window.clear();


        //Update window
        window.display();
    }

    return 0;
}
