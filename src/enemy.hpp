#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "visibleobject.hpp"

class Enemy: public VisibleObject
{
    public:
        virtual ~Enemy() { }
            
        virtual void update(const sf::RenderWindow& fen);
        
        void set_position(float x, float y) { _sprite.SetPosition(x, y); }
        const sf::Vector2f& get_position() const { return _sprite.GetPosition(); }
        sf::Vector2f get_size() const { return _sprite.GetSize(); }
        
    protected:
        // Constructeur protégé pour préciser que c'est une classe abstraite
        Enemy(const std::string& filename, int z=1) : VisibleObject(filename, z) { }
        float _vx;
        float _vy;
};

#endif /* ENEMY_HPP */ 
