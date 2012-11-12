#ifndef MAFIA_HPP
#define MAFIA_HPP

#include "enemy.hpp"

class Mafia: public Enemy
{
    public:
        Mafia (const std::string& filename) : Enemy(filename)
        {
            // TODO : mieux gérer ces paramètres, peut être que ça devrait pas être
            //défini dans la superclasse, ou alors fournir un constructeur correct
            _vx = 0.0f;
            _vy = 200.0f;
        }
        
        void * update(const sf::RenderWindow& fen);
};

#endif
