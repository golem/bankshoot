#ifndef VISIBLEOBJECT_HPP
#define VISIBLEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class VisibleObject
{
    public:
        VisibleObject(const std::string& filename) : _img(), _sprite() 
        {
            _img.LoadFromFile(filename);
            _sprite.SetImage(_img);
            std::cout << "Création d'un objet" << std::endl;
        }
        virtual ~VisibleObject() { std::cout << "Destruction d'un objet" << std::endl; }
        
        virtual void draw(sf::RenderWindow& fen) const;
        virtual void update(const sf::RenderWindow& fen);
    
    protected:
        sf::Image _img;
        sf::Sprite _sprite;
};

#endif /* VISIBLEOBJECT_HPP */ 
