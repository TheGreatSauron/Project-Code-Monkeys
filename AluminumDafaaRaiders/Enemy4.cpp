#include "Enemy4.h"
#include "Game.h"

void Enemy4::scorePoints()
{
	Game::score += 200;
}

Enemy4::Enemy4(sf::Vector2f position, sf::Texture& texture, sf::Texture& laser) : Enemy(position, texture, laser)
{
    speed = 150;
    health = 1;

    sprite.setTextureRect(sf::IntRect(289, 5, 59, 29));
}

sf::FloatRect Enemy4::getGlobalBounds() const
{
    sf::FloatRect hitbox(0, 0, 59, 29);
    hitbox.left = getPosition().x;
    hitbox.top = getPosition().y;
    return hitbox;
}