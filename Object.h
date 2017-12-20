#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/graphics.hpp>
#include <memory>

//Base class for all objects that update every frame
class Object : public sf::Drawable, public sf::Transformable
{
    //Internal track of garbage collection
    bool isDestroyed;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    //Standard constructor
    Object(bool willBeDrawable = false, bool willBeCollidable = false);

    //Call to kill the object and it will get garbage collected
    void destroy();

    //Returns whether the object is waiting for garbage collection
    bool hasBeenDestroyed() const;

    //Is called every frame
    virtual void update(sf::Time deltaTime) =0;

    //Gets the hitbox of the object
    virtual sf::FloatRect getGlobalBounds() const;

    //Checks if an object will collide with another
    virtual bool isColliding(std::unique_ptr<Object>& collidingObject);

    //Used to determine if this class is meant to be drawn
    //Should be defined at costruction
    //Is not const and can change
    bool isDrawable;

    //Should this object check for collision
    bool isCollidable;
};

#endif // OBJECT_H_INCLUDED
