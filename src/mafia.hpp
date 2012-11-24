#ifndef MAFIA_HPP
#define MAFIA_HPP

/**
 * @file mafia.hpp
 */

#include "enemy.hpp"
#include "constants.hpp"

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
        Mafia (const std::string& filename) : Enemy(filename), _elapsed_time(0.0f), _shot_delay(MAFIA_SHOT_DELAY)
        {
            // TODO : mieux gérer ces paramètres, peut être que ça devrait pas être
            //défini dans la superclasse, ou alors fournir un constructeur correct
            _vx = 0.0f;
            _vy = MAFIA_SPEED;
        }
        
        void * update(const sf::RenderWindow& fen);
    private:
        float _elapsed_time;
        float _shot_delay;
};

#endif
