#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "collidingobject.hpp"
#include "enemy.hpp"

class Banquier: public CollidingObject
{
    public:
        Banquier(const std::string& filename, int z=10) : CollidingObject(filename, z), _vx(200.0f), _vy(200.0f)
        {
           //TODO: Vitesses et position arbitraires, sûrement à changer, plus tard 
           _sprite.SetPosition(200.0f, 2000.0f);
        }
        
        void update(const sf::RenderWindow& fen);
        
        void collision(CollidingObject * o);
        
    private:
        float _vx;
        float _vy;
};

#endif /* PLAYER_HPP */ 
