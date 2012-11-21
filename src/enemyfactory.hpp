#ifndef ENEMY_FACTORY_HPP
#define ENEMY_FACTORY_HPP

/**
 * @file enemyfactory.hpp
 * @brief Génération aléatoire des ennemis
 */

#include "enemy.hpp"
#include "voleur.hpp"
#include "mafia.hpp"
#include "client.hpp"
#include "boss.hpp"
#include "constants.hpp"


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
            thief,  /**< Ennemi du type \a Voleur */
            mafia,  /**< Ennemi du type \a Mafia */
            client, /**< Ennemi du type \a Client */
            boss    /**< Boss du jeu */
        };
        
        /**
         * @brief Constructeur
         */
        EnemyFactory(): _boss_added(false), _enemi_count(0) { _clock.Reset(); }
        
        /**
         * @brief Destructeur
         */
        ~EnemyFactory() {}
        
        /**
         * @brief Créer un ennemi
         * 
         * Il est nécessaire de connaître la position du banquier, afin que
         * les tirs des ennemis soient dans la direction de ce dernier
         * 
         * @param banquier Pointeur sur le banquier
         * @return Pointeur sur l'ennemi créé
         */
        Enemy* generate(Banquier *banquier);

        /**
         * @brief Redémarre le \a clock
         */
        void restart() { _clock.Reset(); }
        
        /**
         * @brief Donne le temps de la dernière apparition d'un ennemi
         * @return Temps
         */
        float get_last_enemy_time();

        /**
         * @brief Savoir si un boss est présent
         * 
         * Lorsqu'un boss est présent, tous les autres types d'ennemi n'apparaissent
         * plus
         * 
         * @return Booléen
         */ 
        bool has_boss() const { return _boss_added; }

        /**
         * @brief Réinitialise le boss
         */
        void reset_boss()
        {
            _enemi_count = 0;
            _boss_added = false;
        }

    private:

        /**
         * @brief Retourne un type d'ennemi au hasard
         * @return Type d'ennemi
         */
        Enemy_type random_type();

        sf::Clock _clock;   ///< Clock
        bool _boss_added;   ///< \a true si un boss est présent
        int _enemi_count;     ///< Compteur : nombre d'ennemis apparus
};

#endif
