#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "visibleobject.hpp"

class Enemy: public VisibleObject
{
    public:
        Enemy(const std::string& filename, int z=1) : VisibleObject(filename, z)
        {
            _vx = 0.0f;
            _vy = 100.0f;
        }
            
        void update(const sf::RenderWindow& fen);
        
    private:
        float _vx;
        float _vy;
};

#endif /* ENEMY_HPP */ 
