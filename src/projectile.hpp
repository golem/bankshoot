#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

/**
 * @file projectile.hpp
 * @brief Gestion des projectiles
 */

#include "visibleobject.hpp"

#include <string>

/**
 * @class Projectile
 * @brief Gérer les objets lancés par les personnages
 */
class Projectile: public VisibleObject
{
    public:

        /**
         * @brief Constructeur
         * 
         * Appelle le constructeur de \a VisibleObject
         */
        Projectile(const std::string& filename, float x, float y, int vy=-200.0f):
            VisibleObject(filename, 20), _vy(vy)
        {
           _sprite.SetPosition(x, y);
        }

        /**
         * @brief Destructeur
         */
         ~Projectile() {}
         
         /**
          * @brief Mettre à jour la position
          */
        void update(const sf::RenderWindow& fen);
        
    private:
        float _vy; /**< Vitesse suivant l'ordonné */
};

#endif
