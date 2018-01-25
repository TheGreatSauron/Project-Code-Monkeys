#include "HealthBar.h"
#include "Resources.h"

void HealthBar::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states = getTransform();
	target.draw(text, states);

	states.transform.translate(text.getLocalBounds().width + 10, 5);
	target.draw(outline, states);
	target.draw(inside, states);
}

HealthBar::HealthBar(int life) : Object(true), maxLife(life)
{
	setPosition(0, 0);

	text.setFont(Resources::Arial);
	text.setString("Health:");

	outline.setFillColor(sf::Color::Transparent);
	outline.setOutlineThickness(2);
	outline.setOutlineColor(sf::Color::White);

	inside.setFillColor(sf::Color::Red);
}

void HealthBar::updateHealth(int life)
{
	inside.setSize(sf::Vector2f(50 * life, inside.getSize().y));
}

void HealthBar::reset(int life)
{
	maxLife = life;

	outline.setSize(sf::Vector2f(50 * maxLife, text.getLocalBounds().height));
	inside.setSize(outline.getSize());
}

void HealthBar::update(sf::Time deltaTime)
{
}
