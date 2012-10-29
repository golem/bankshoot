#ifndef OBJECTMANAGER_HPP
#define OBJECTMANAGER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "visibleobject.hpp"

class ObjectManager
{
    public:
        ObjectManager() : _objects(0) { }
        ~ObjectManager()
        {
            delete_all();
        }
        
        void delete_all();
        void draw_all(sf::RenderWindow& fen) const;
        
        void operator+=(VisibleObject * obj);
    
    private:
        std::vector<VisibleObject *> _objects;
};

#endif /* OBJECTMANAGER_HPP */ 
