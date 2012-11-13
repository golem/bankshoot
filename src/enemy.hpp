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

// Les 3 méthodes suivantes sont peut-être mieux de les déclarer dans la super classe        

        /**
         * @brief Fixer la position de l'ennemi au départ
         * @param x Coordonnée x
         * @param y Coordonnée y
         */
        void set_position(float x, float y) { _sprite.SetPosition(x, y); }
        
        /**
         * @brief Connaitre la position actuelle
         * @return Position actuelle
         */
        const sf::Vector2f& get_position() const { return _sprite.GetPosition(); }
        
        /**
         * @brief Connaitre la taille du sprite
         * @return Taille du sprite
         */
        sf::Vector2f get_size() const { return _sprite.GetSize(); }

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
