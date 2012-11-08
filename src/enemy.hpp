#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "collidingobject.hpp"
#include "banquier.hpp"

class Enemy: public CollidingObject
{
    public:
        virtual ~Enemy() { }
            
        virtual void update(const sf::RenderWindow& fen);
        
        virtual void collision(CollidingObject * o);
        
    protected:
        // Constructeur protégé pour préciser que c'est une classe abstraite
        Enemy(const std::string& filename, int z=1) : CollidingObject(filename, z) { }
        float _vx;
        float _vy;
};

#endif /* ENEMY_HPP */ 
