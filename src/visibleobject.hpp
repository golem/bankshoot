#ifndef VISIBLEOBJECT_HPP
#define VISIBLEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class VisibleObject
{
    public:
        VisibleObject(const std::string& filename, int z=0) : _img(), _sprite(), _z(z)
        {
            _img.LoadFromFile(filename);
            _img.SetSmooth(false); // Pour éviter le filtrage
            _sprite.SetImage(_img);
            std::cout << "Création d'un objet" << std::endl;
        }
        virtual ~VisibleObject() { std::cout << "Destruction d'un objet" << std::endl; }
        
        virtual void draw(sf::RenderWindow& fen) const;
        virtual void update(const sf::RenderWindow& fen) = 0;
        
        bool operator<(const VisibleObject& that) const
        {
            if (_z < that._z) return true;
            return false;
        }
    
    protected:
        sf::Image _img;
        sf::Sprite _sprite;
        int _z;
};

#endif /* VISIBLEOBJECT_HPP */ 
