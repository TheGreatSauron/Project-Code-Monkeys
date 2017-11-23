#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "SFML/graphics.hpp"

//Base class for all objects that update every frame
class Object : public sf::Drawable, public sf::Transformable
{
public:
    //Is called every frame
    virtual void update(sf::Time DeltaTime) =0;

    //Used to determine if this class is meant to be drawn
    //Should be defined at costruction
    //Is not const and can change for deleted things
    bool isDrawable;
};

#endif // OBJECT_H_INCLUDED
