#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "visibleobject.hpp"

class Enemy: public VisibleObject
{
    public:
        virtual ~Enemy() { }
            
        virtual void update(const sf::RenderWindow& fen);
        
    protected:
        // Constructeur protégé pour préciser que c'est une classe abstraite
        Enemy(const std::string& filename, int z=1) : VisibleObject(filename, z) { }
        float _vx;
        float _vy;
};

#endif /* ENEMY_HPP */ 
