#ifndef REPEATINGOBJECT_HPP
#define REPEATINGOBJECT_HPP

#include "visibleobject.hpp"

class Background: public VisibleObject
{
    public:
        Background(const std::string& filename, int vitesse, int z=-1) : VisibleObject(filename, z), _vitesse(vitesse)
        {
            _sprite_bis.SetImage(_img);
            _position[0] = -(float) _img.GetHeight();
            _position[1] = 0.0f;
        }
        
        void update(const sf::RenderWindow& fen);
        void draw(sf::RenderWindow& fen) const;
            
    private:
        int _vitesse;
        sf::Sprite _sprite_bis;
        float _position[2];
};

#endif /* REPEATINGOBJECT_HPP */ 
