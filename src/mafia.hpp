#ifndef MAFIA_HPP
#define MAFIA_HPP

/**
 * @file mafia.hpp
 */

#include "enemy.hpp"

/**
 * @class Mafia
 * @brief Ennemi un peu plus intelligent
 */
class Mafia: public Enemy
{
    public:
    
        /**
         * @brief Constructeur
         */
        Mafia (const std::string& filename) : Enemy(filename)
        {
            // TODO : mieux gérer ces paramètres, peut être que ça devrait pas être
            //défini dans la superclasse, ou alors fournir un constructeur correct
            _vx = 0.0f;
            _vy = MAFIA_SPEED;
        }
        
        void * update(const sf::RenderWindow& fen);
};

#endif
