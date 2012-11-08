#ifndef BANQUIER_HPP
#define BANQUIER_HPP

/**
 * @file banquier.hpp
 * @brief Contient la classe contrôlée par le joueur.
 */

#include "collidingobject.hpp"
#include "enemy.hpp"

/**
 * @brief Le personnage principal : un banquier qui défend la banque.
 **/
class Banquier: public CollidingObject
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param filename Le chemin de l'image à utiliser.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 10.)
         **/
        Banquier(const std::string& filename, int z=10) : CollidingObject(filename, z), _vx(200.0f), _vy(200.0f)
        {
           //TODO: Vitesses et position arbitraires, sûrement à changer, plus tard 
           _sprite.SetPosition(200.0f, 2000.0f);
        }
        
        /**
         * @brief Déplace le banquier en fonction des touches appuyées.
         *
         * @param fen La fenêtre de rendu.
         * @return void
         **/
        void update(const sf::RenderWindow& fen);
        
        void collision(CollidingObject * o);
        
    private:
        float _vx;
        float _vy;
};

#endif /* BANQUIER_HPP */ 
