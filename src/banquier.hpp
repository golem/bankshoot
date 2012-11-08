#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "visibleobject.hpp"
#include "constants.hpp"

class Banquier: public VisibleObject
{
    public:
        Banquier(const std::string& filename, int z=10) : VisibleObject(filename, z), _vx(200.0f), _vy(200.0f)
        {
           //TODO: Vitesses et position arbitraires, sûrement à changer, plus tard 
           _sprite.SetSubRect(sf::IntRect(32, 43, 63, 0));
           _sprite.SetPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT);
        }
        
        void update(const sf::RenderWindow& fen);
        
    private:
        float _vx;
        float _vy;
};

#endif /* PLAYER_HPP */ 
