#ifndef ENEMY_FACTORY_HPP
#define ENEMY_FACTORY_HPP

/**
 * @file enemyfactory.hpp
 * @brief Génération aléatoire des ennemies
 */

#include "enemy.hpp"

#include <cstdlib>
#include <ctime>

/**
 * @class EnemyFactory
 * @brief Classe générant les ennemies de manière aléatoire
 */
class EnemyFactory
{
    public:

        /**
         * @enum Enemy_type
         * @brief Type d'ennemies
         * 
         * Définir tous les types d'ennemies disponibles dans le jeu
         */
        enum Enemy_type {
            thief /**< Ennemie du type \a Voleur*/
        };
        
        /**
         * @brief Constructeur
         */
        EnemyFactory(): _has_enemy(false) { srand(time(NULL)); }
        
        /**
         * @brief Destructeur
         */
        ~EnemyFactory() {}
        
        /**
         * @brief Créer un ennemie
         * @param type : Type d'ennemie à créer
         * @return Pointeur sur l'ennemie créé
         */
        Enemy* generate(Enemy_type type);

        /**
         * @brief Vérifier si un ennemie est susceptible de créé
         */
        void check();

        /**
         * @brief Retourne \a true si un ennemie est disponible
         */
        bool has_enemy()
        {
            check();
            return _has_enemy;
        }
        
        /**
         * @brief Connaître le type d'ennemie à créer
         */
        Enemy_type get_type() const { return _type; }

        static const int PROBABILITY = 100; /**< Probabilité de créer un ennemie */

    private:
        bool _has_enemy; /**< \a true si un ennemie peut être créé */
        Enemy_type _type; /**< Le type d'ennemie à créé */
};

#endif
