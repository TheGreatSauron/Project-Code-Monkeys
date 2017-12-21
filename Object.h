#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/graphics.hpp>
#include <memory>
#include <typeinfo>

//Base class for all objects that update every frame
class Object : public sf::Drawable, public sf::Transformable
{
    //Internal track of garbage collection
    bool isDestroyed;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    //Standard constructor, use typeid to define typeCollider if it collides with something
    Object(bool willBeDrawable = false, const std::type_info* typeCollider = nullptr);

    //Call to kill the object and it will get garbage collected
    void destroy();

    //Returns whether the object is waiting for garbage collection
    bool hasBeenDestroyed() const;

    //Is called every frame
    virtual void update(sf::Time deltaTime) =0;

    //Gets the hitbox of the object
    virtual sf::FloatRect getGlobalBounds() const;

    //Used to determine if this class is meant to be drawn
    //Should be defined at costruction
    //Is not const and can change
    bool isDrawable;

    //Called either if this object collides with something or if another object collides with it
    //collisionObject is the other object involved in the collision
    virtual void collide(std::unique_ptr<Object>& collisionObject);

    //What it collides with, set to nullptr if no collision
    const std::type_info* collider;
};

#endif // OBJECT_H_INCLUDED
