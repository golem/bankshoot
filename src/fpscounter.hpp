#ifndef FPSCOUNTER_HPP
#define FPSCOUNTER_HPP

#include <string>
#include <sstream>

#include "visibleobject.hpp"

class FPSCounter: public VisibleObject
{
    public:
        FPSCounter(const std::string& filename) : VisibleObject(50),
                            _font(ResourceManager::get_font(filename))
        {
            _texte.SetFont(*_font);
        }
        
        void draw(sf::RenderWindow& fen) const;
        void update(const sf::RenderWindow& fen);
            
    private:
        sf::Font * _font;
        sf::String _texte;
};

#endif /* FPSCOUNTER_HPP */ 
