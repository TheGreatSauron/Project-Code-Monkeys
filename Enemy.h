#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "Object.h"
#include "Spline.h"

class Collision : public Object
{
    sf::RectangleShape rectangle;
public:
    Collision(sf::Vector2f position) : Object(true, true), rectangle(sf::Vector2f(100, 100))
    {
        setPosition(position);

        rectangle.setFillColor(sf::Color::Red);
    }
    void update(sf::Time deltaTime)
    {
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states = getTransform();
        target.draw(rectangle, states);
    }
    sf::FloatRect getGlobalBounds() const
    {
        sf::FloatRect hitbox(rectangle.getLocalBounds());
        hitbox.left = getPosition().x;
        hitbox.top = getPosition().y;
        return hitbox;
    }
};

class Enemy : public Object
{
private:

   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:

	// Current Health
	int health;

	// Enemy speed
	float speed;

	// Shoots a laser
	virtual void shootLaser();

public:

    // Constructor declaration
	Enemy(sf::Vector2f postition, sf::Texture& texture, sf::Texture& laser);

    // Deals damage to current health
	void dealDamage(int damage);

	// What occurs every frame
	virtual void update(sf::Time deltaTime) override;

    // Declares sprites
    sf::Sprite sprite;
    sf::Texture& laserTexture;

    // Spline class
    Spline spline;

};

#endif
