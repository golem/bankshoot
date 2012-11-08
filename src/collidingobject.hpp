#ifndef COLLIDINGOBJECT_HPP
#define COLLIDINGOBJECT_HPP

#include "visibleobject.hpp"

#include <SFML/Graphics.hpp>
#include <string>

class CollidingObject : public VisibleObject
{
    public:
        CollidingObject(int z=0) : VisibleObject(z) { }
        CollidingObject(const std::string& filename, int z=0) : VisibleObject(filename, z) { }
        virtual ~CollidingObject() {  }
        
        sf::FloatRect get_rect() const
        {
            sf::Vector2f size = _sprite.GetSize();
            sf::Vector2f pos = _sprite.GetPosition();
            return sf::FloatRect(pos.x, pos.y, pos.x + size.x, pos.y + size.y);
        }
        bool collides_with(const CollidingObject& o) { return this->get_rect().Intersects(o.get_rect()); }
        virtual void collision(CollidingObject * o) = 0;
};

#endif /* COLLIDINGOBJECT_HPP */ 
