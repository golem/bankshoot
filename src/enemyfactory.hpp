#ifndef ENEMY_FACTORY_HPP
#define ENEMY_FACTORY_HPP

/**
 * @file enemyfactory.hpp
 * @brief Génération aléatoire des ennemis
 */

#include "enemy.hpp"

#include <SFML/System/Clock.hpp>

/**
 * @class EnemyFactory
 * @brief Classe générant les ennemis de manière aléatoire
 */
class EnemyFactory
{
    public:

        /**
         * @enum Enemy_type
         * @brief Type d'ennemis
         * 
         * Définir tous les types d'ennemies disponibles dans le jeu
         */
        enum Enemy_type {
            thief, /**< Ennemi du type \a Voleur*/
            mafia
        };
        
        /**
         * @brief Constructeur
         */
        EnemyFactory() { _clock.Reset(); }
        
        /**
         * @brief Destructeur
         */
        ~EnemyFactory() {}
        
        /**
         * @brief Créer un ennemi
         * @return Pointeur sur l'ennemi créé
         */
        Enemy* generate() const;
        
        /**
         * @brief Redémarre le \a clock
         */
        void restart() { _clock.Reset(); }
        
        /**
         * @brief Donne le temps de la dernière apparition d'un ennemi
         * @return Temps
         */
        float get_last_enemy_time() { return _clock.GetElapsedTime(); }

    private:

        /**
         * @brief Retourne un type d'ennemi au hasard
         * @return Type d'ennemi
         */
        Enemy_type random_type() const;

        sf::Clock _clock; /**< Clock */
};

#endif
