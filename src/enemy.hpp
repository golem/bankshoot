#ifndef ENEMY_HPP
#define ENEMY_HPP

/**
 * @file enemy.hpp
 * @brief Base pour tous les ennemis.
 */

#include "collidingobject.hpp"
#include "banquier.hpp"
#include "projectile.hpp"
#include "dropobject.hpp"
#include "constants.hpp"

/**
 * @brief Classe de base de tous les ennemis du jeu.
 **/
class Enemy: public CollidingObject
{
    public:
        /**
         * @brief Destructeur (virtuel pour autoriser un héritage correct).
         *
         **/
        virtual ~Enemy() { }
            
        virtual void * update(const sf::RenderWindow& fen);

        /**
         * @brief Fait mourir l'Enemy lors d'une collision avec le Banquier (à améliorer).
         *
         * @param o Le CollidingObject avec lequel il y a eu collision.
         * @return void
         **/
        virtual void* collision(CollidingObject * o);
        
    protected:
        /**
         * @brief Constructeur (protégé pour préciser que c'est une classe abstraite).
         *
         * @param filename Chemin de l'image à utiliser.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 1.)
         **/
        Enemy(const std::string& filename, int z=1) : CollidingObject(filename, z) { }
        float _vx; ///< Vitesse horizontale.
        float _vy; ///< Vitesse verticale.
};

#endif /* ENEMY_HPP */ 
