#include "Enemy2.h"
#include "Game.h"

void Enemy2::scorePoints()
{
	Game::score += 500;
}

Enemy2::Enemy2(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 80;
    health = 3;

    sprite.setTextureRect(sf::IntRect(51, 1, 66, 98));
}

sf::FloatRect Enemy2::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 66, 98);
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}
