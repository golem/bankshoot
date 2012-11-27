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
            thief,  ///< Ennemi du type \a Voleur
            mafia,  ///< Ennemi du type \a Mafia
            client, ///< Ennemi du type \a Client
            boss    ///< Boss du jeu
        };
        
        /**
         * @brief Constructeur
         * 
         * Réinitialise \a Clock
         */
        EnemyFactory() { _clock.Reset(); }
        
        /**
         * @brief Destructeur
         * 
         * Réinitialise la difficulté
         */
        ~EnemyFactory()
        {
            reset_boss();
            reset_level();
        }
        
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
         * @brief Connaître le niveau du jeu
         * @return Le niveau de difficulté
         */
        static int level() { return _level; }

        /**
         * @brief Réinitialise le boss
         */
        static void reset_boss()
        {
            _enemi_count = 0;
            _boss_added = false;
        }
        
        /**
         * @brief Augmenter le niveau de difficulté
         */
        static void next_level() { ++_level; }

        /**
         * @brief Réinitialise le niveau de difficulté
         */
        static void reset_level() { _level = 1; }

    private:

        /**
         * @brief Retourne un type d'ennemi au hasard
         * @return Type d'ennemi
         */
        Enemy_type _random_type();

        /**
         * @brief Sélectionne au hasard une image pour le boss
         * @return Nom du l'image
         */
        const std::string _select_boss_sprite();

        sf::Clock _clock;           ///< Clock
        static bool _boss_added;    ///< \a true si un boss est présent
        static int _enemi_count;    ///< Compteur : nombre d'ennemis apparus
        static int _level;          ///< Niveau de difficulté
};

#endif
