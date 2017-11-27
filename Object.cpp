#include "Object.h"

Object::Object(bool willBeDrawable) : isDrawable(willBeDrawable), isDestroyed(false) {}

void Object::destroy()
{
    isDestroyed = true;
}

bool Object::hasBeenDestroyed() const
{
    return isDestroyed;
}
