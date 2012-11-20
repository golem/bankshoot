#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

/**
 * @file projectile.hpp
 * @brief Gestion des projectiles
 */

#include "collidingobject.hpp"
#include "enemy.hpp"

#include <string>

/**
 * @class Projectile
 * @brief Gérer les objets lancés par les personnages
 */
class Projectile: public CollidingObject
{
    public:
    
        /**
         * @enum shot_id
         * @brief Connaître l'auteur des tirs
         */
        enum shot_id {
            banker, ///< Projectiles appartenant au banquier
            enemy   ///< Projectiles appartenant aux ennemis
        };

        /**
         * @brief Constructeur
         * @param filename
         * @param x
         * @param y
         * @param id
         * @param vy
         * @param vx
         * Appelle le constructeur de \a CollidingObject
         */
        Projectile(const std::string& filename, float x, float y, shot_id id, float vy=-BANKER_SHOT_SPEED, float vx=0.0f):
            CollidingObject(filename, 20), _id(id), _vy(vy), _vx(vx)
        {
            // TODO: Réfléchir à améliorer ce constructeur (vitesse +/-, position par rapport au créateur, etc.)
           _sprite.SetPosition(x, y);
        }

        /**
         * @brief Destructeur
         */
         ~Projectile() {}
         
         /**
          * @brief Mettre à jour la position
          * @param fen
          */
        void * update(const sf::RenderWindow& fen);
        
        virtual void * collision(CollidingObject * o);
        
        
        shot_id get_shot_id() { return _id; }
    private:
        shot_id _id;  ///< Identifiant du tireur
        float _vy;  ///< Vitesse suivant l'ordonné
        float _vx;  ///< Vitesse suivant l'abscisse
};

#endif
