#ifndef VISIBLEOBJECT_HPP
#define VISIBLEOBJECT_HPP

#include "object.hpp"

#include <SFML/Graphics.hpp>
#include <string>

class VisibleObject : public Object
{
    public:
        VisibleObject(const std::string& filename, int z=0) : Object(z), _img(), _sprite()
        {
            _img.LoadFromFile(filename);
            _img.SetSmooth(false); // Pour éviter le filtrage
            _sprite.SetImage(_img);
        }
        virtual ~VisibleObject() {  }
        
        virtual void draw(sf::RenderWindow& fen) const;
        virtual void update(const sf::RenderWindow& fen) = 0;
    
    protected:
        sf::Image _img;
        sf::Sprite _sprite;
};

#endif /* VISIBLEOBJECT_HPP */ 
