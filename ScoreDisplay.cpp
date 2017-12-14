#include "ScoreDisplay.h"
#include "Game.h"

void ScoreDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states = getTransform();

    target.draw(text, states);
}

ScoreDisplay::ScoreDisplay(sf::Font& font, sf::Vector2f position) : Object(true)
{
    //Set the font of the text
    text.setFont(font);

    //Update the text
    update(sf::seconds(0));

    //Set the position of the object
    setPosition(position);
}

void ScoreDisplay::update(sf::Time deltaTime)
{
    //Update the string
    text.setString("Score: " + Game::to_string(Game::score));

    //Reset the origin so that the text stays in the screen
    setOrigin(text.getLocalBounds().width + 5, 0);
}
