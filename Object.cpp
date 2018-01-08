#include "Object.h"

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

Object::Object(bool willBeDrawable)
 : isDrawable(willBeDrawable), isDestroyed(false) {}

void Object::destroy()
{
    isDestroyed = true;
}

bool Object::hasBeenDestroyed() const
{
    return isDestroyed;
}

sf::FloatRect Object::getGlobalBounds() const
{
    return sf::FloatRect(0, 0, 0, 0);
}

void Object::collide(std::unique_ptr<Object>& collisionObject)
{
}
