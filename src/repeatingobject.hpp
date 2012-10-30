#ifndef REPEATINGOBJECT_HPP
#define REPEATINGOBJECT_HPP

#include "visibleobject.hpp"

class RepeatingObject: public VisibleObject
{
    public:
        RepeatingObject(const std::string& filename) : VisibleObject(filename) { }
        
        void update(const sf::RenderWindow& fen);
        void draw(sf::RenderWindow& fen) const;
            
    private:
        /* add your private declarations */
};

#endif /* REPEATINGOBJECT_HPP */ 
