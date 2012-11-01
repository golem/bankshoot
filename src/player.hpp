#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "visibleobject.hpp"

class Player: public VisibleObject
{
    public:
        Player(const std::string& filename) : VisibleObject(filename), _vx(200.0f), _vy(200.0f)
        {
           //TODO: Vitesses et position arbitraires, sûrement à changer, plus tard 
           _sprite.SetPosition(200.0f, 2000.0f);
        }
        
        void update(const sf::RenderWindow& fen);
        
    private:
        float _vx;
        float _vy;
};

#endif /* PLAYER_HPP */ 
