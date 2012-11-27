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
         * @param filename Chemin de l'image à afficher
         */
        Mafia (const std::string& filename): Enemy(filename),
                                             _elapsed_time(0.0f),
                                             _shot_delay(MAFIA_SHOT_DELAY)
        {
            _vx = 0.0f;
            _vy = MAFIA_SPEED;
        }

        /**
         * @brief Met à jour l'objet.
         * 
         * Cet ennmemi peut tirer des balles
         *
         * @param fen Fenêtre de rendu à laquelle appartient l'objet.
         * @return Pointeur vers un éventuel \a Projectile
         **/
        void * update(const sf::RenderWindow& fen);

    private:
        float _elapsed_time; ///< Temps du dernier tir
        float _shot_delay; ///< Délai entre deux tirs
};

#endif
